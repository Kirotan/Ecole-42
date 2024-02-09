/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:55:24 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/09 18:19:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *str, char **envp)
{
	char	*path;
	char	**tab;
	int		i;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	path = ft_strjoin("/bin/", tab[0]);
	i = 0;
	if (path == NULL)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
		exit(1);
	}
	execve(path, tab, envp);
}
