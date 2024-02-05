/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:41:05 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 19:19:29 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	verif_1(char *str, t_stray *array, int *i, int *j)
{
	free(str);
	while (*i < *j)
	{
		free(array[*i].color);
		(*i)++;
	}
	free(array);
	perror("Malloc error.\n");
	exit (EXIT_FAILURE);
}

void	verif_2(char *str, t_stray *array, int *i, int *j)
{
	free(str);
	while (*i < *j)
	{
		free(array[*i].color);
		(*i)++;
	}
	free(array);
	perror("Bad digit.\n");
	exit (EXIT_FAILURE);
}

void	verif_3(char *str, t_stray *array, int *i, int *j)
{
	if (!array[*j].color)
	{
		free(str);
		while (*i < *j)
		{
			free(array[*i].color);
			(*i)++;
		}
		free(array);
		perror("Malloc error, transparent line.\n");
		exit (EXIT_FAILURE);
	}
}

void	verif_4(t_stray *array, char **points, char *point_str, int *j)
{
	if (!array[*j].color)
	{
		free(point_str);
		free(points);
	}
}

void	verif_5(t_stray *array, int *j, int i)
{
	if (i != array[0].len_line)
	{
		i = 0;
		while (i < *j)
		{
			free(array[i].color);
			i++;
		}
		free(array);
		perror("Bad line.\n");
		exit (EXIT_FAILURE);
	}
}

#define malloc(x) {static int i = 0; if (i++ == 10){return malloc(x);} else {return (NULL);}}
