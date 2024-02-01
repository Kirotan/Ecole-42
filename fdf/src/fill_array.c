/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:45 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/01 14:02:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	extract_and_convert(char *final_line, t_coordinates *coords,
	t_stray *array)
{
	char	*temp;
	int		result;

	temp = ft_substr(final_line, coords->start, coords->i - coords->start);
	r_g_b(temp, array, *coords);
	result = ft_atoi(temp);
	array[coords->j].z = (result * 1);
	array[coords->j].x = (coords->x * 30) + (array[coords->j].start_x
			- (array[0].len_line * 30) / 2);
	array[coords->j].y = (coords->y * 30) + (array[coords->j].start_y
			+ ((array[0].len_total / array[0].len_line) * 30) / 2);
	free(temp);
	return ;
}

static void	increment_coordinates(int *x, int *y, int len)
{
	if (*x + 1 == len)
	{
		*x = 0;
		(*y)++;
	}
	else
		(*x)++;
}

static t_stray	*allocate_memory_stray(size_t len_total)
{
	t_stray	*array;

	array = (t_stray *)ft_calloc(sizeof(t_stray), len_total);
	if (!array)
		return (NULL);
	return (array);
}

int	split_line_into_array(t_stray *array, size_t len, char *final_line, char c)
{
	t_coordinates	coords;

	coords.i = 0;
	coords.x = 0;
	coords.y = 0;
	coords.j = 0;
	while (final_line[coords.i])
	{
		if (final_line[coords.i] == c)
			coords.i++;
		if (final_line[coords.i] != c && final_line[coords.i])
		{
			coords.start = coords.i;
			while (final_line[coords.i] && final_line[coords.i] != c)
				coords.i++;
			extract_and_convert(final_line, &coords, array);
			increment_coordinates(&coords.x, &coords.y, len);
			coords.j++;
		}
	}
	return (0);
}

t_stray	*fill_array(char *final_line, size_t len)
{
	t_stray	*array;
	size_t	len_total;
	char	c;

	c = 32;
	len_total = ft_count_words(final_line, 32);
	array = allocate_memory_stray(len_total);
	array[0].len_total = len_total;
	array[0].len_line = len;
	calcul_center(array);
	split_line_into_array(array, len, final_line, c);
	return (array);
}
