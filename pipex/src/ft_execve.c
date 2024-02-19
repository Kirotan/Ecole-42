/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:55:24 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/18 16:26:00 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char *tab, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, tab);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	ft_execve(char *str, char **envp)
{
	char	*path;
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	path = find_path(tab[0], envp);
	if (!path)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
		perror("Error path.\n");
		exit(EXIT_FAILURE);
	}
	if (access(path, F_OK) == -1)
		ft_error_malloc(tab);
	if (execve(path, tab, envp) == -1)
		ft_error_exerve();
}
