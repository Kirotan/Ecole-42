/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:47 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/18 15:43:53 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_process_child(char **argv, int *fd, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	ft_error_file(filein);
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(filein);
	ft_execve(argv[2], envp);
}

static void	ft_process_parent(char **argv, int *fd, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_error_file(fileout);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	close(fileout);
	ft_execve(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error_pipe();
		pid = fork();
		if (pid == -1)
			ft_error_fork();
		if (pid == 0)
			ft_process_child(argv, fd, envp);
		waitpid(pid, NULL, 0);
		ft_process_parent(argv, fd, envp);
	}
	return (0);
}
