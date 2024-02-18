/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:55:24 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/09 19:50:00 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *str, char **envp)
{
	char	*path;
	char	**tab;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	path = ft_strjoin("/bin/", tab[0]);
	if (access(path, F_OK) == -1)
		ft_error_malloc(tab);
	if (execve(path, tab, envp) == -1)
		ft_error_exerve();
}
