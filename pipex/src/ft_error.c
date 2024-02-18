/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:37:17 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/09 19:50:16 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_malloc(char **tab)
{
	int	i;

	i = 0;
	perror("Error malloc.\n");
	while (tab[i])
		free(tab[i++]);
	free(tab);
	exit(1);
}

void	ft_error_exerve(void)
{
	perror("Error execve.\n");
	exit(1);
}

void	ft_error_file(int filein)
{
	if (filein == -1)
	{
		perror("Error filein.\n");
		exit(1);
	}
}

void	ft_error_pipe(void)
{
	perror("Error pipe.\n");
	exit(1);
}

void	ft_error_fork(void)
{
	perror("Error fork.\n");
	exit(1);
}
