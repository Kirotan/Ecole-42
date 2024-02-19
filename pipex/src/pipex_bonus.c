/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:51:59 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/19 10:51:43 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_process_child_bonus(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("Pipe error.\n");
	pid = fork();
	if (pid == -1)
		perror("PID error.\n");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execve(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		i = 2;
		fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		filein = open(argv[1], O_RDONLY);
		dup2(filein, STDIN_FILENO);
		while (i < argc - 2)
			ft_process_child_bonus(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_execve(argv[argc - 2], envp);
	}
	return (0);
}
