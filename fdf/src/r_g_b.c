/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_g_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:29:06 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 21:08:54 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	blue_color(char *color)
{
	char	*blue;
	size_t	i;

	i = 0;
	if (ft_strlen(color) < 6)
		return (0);
	blue = (char *)ft_calloc(sizeof(char), 3);
	while (color[i] && i < 2)
	{
		blue[i] = color[i + 4];
		i++;
	}
	blue[3] = '\0';
	return (0);
}

static int	green_color(char *color)
{
	char	*green;
	size_t	i;

	i = 0;
	if (ft_strlen(color) < 4)
		return (0);
	green = (char *)ft_calloc(sizeof(char), 3);
	while (color[i] && i < 2)
	{
		green[i] = color[i + 2];
		i++;
	}
	green[3] = '\0';
	return (0);
}

static int	red_color(char *color)
{
	char	*red;
	size_t	i;

	i = 0;
	red = (char *)ft_calloc(sizeof(char), 3);
	while (color[i] && i < 2)
	{
		red[i] = color[i];
		i++;
	}
	red[3] = '\0';
	return (0);
}

static char	*find_color(char *temp)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*color;

	i = 0;
	j = 0;
	k = 0;
	color = NULL;
	while (temp[i] && temp[i] != 'x')
		i++;
	if (temp[i] && temp[i] == 'x')
		i++;
	k = i;
	while (temp[i++])
		j++;
	if (j > 0)
		color = (char *)ft_calloc(sizeof(char), j + 1);
	if (!color)
		return (NULL);
	j = 0;
	while (temp[k])
		color[j++] = temp[k++];
	color[j] = '\0';
	return (color);
}

void	r_g_b(char *temp, t_stray *array, t_coordinates coords)
{
	char	*color;

	color = find_color(temp);
	if (!color)
		return ;
	array[coords.j].r = red_color(color);
	array[coords.j].g = green_color(color);
	array[coords.j].b = blue_color(color);
	free(color);
}
