/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:45 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 15:35:19 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stray	*allocate_memory_stray(size_t len_total)
{
	t_stray	*array;

	array = (t_stray *)ft_calloc(sizeof(t_stray), len_total);
	if (!array)
		return (NULL);
	return (array);
}

int	split_line_into_array(t_stray *array, size_t len, char *final_line)
{
	size_t	i;
	size_t	j;
	size_t	start;
	int		x;
	int		y;
	char	c;
	char	*temp;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	c = 32;
	while (final_line[i])
	{
		if (final_line[i] == c)
			i++;
		if (final_line[i] != c && final_line[i])
		{
			start = i;
			while (final_line[i] && final_line[i] != c)
				i++;
			temp = ft_substr(final_line, start, i - start);
			array[j].z = ft_atoi(temp);
			array[j].x = x;
			array[j].y = y;
			if (x + 1 == (int)len)
				y++;
			if (x + 1 == (int)len)
				x = -1;
			x++;
			j++;
		}
	}
	return (0);
}

t_stray	*fill_array(char *final_line, size_t len)
{
	t_stray	*array;
	size_t	len_total;

	len_total = ft_count_words(final_line, 32);
	array = allocate_memory_stray(len_total);
	split_line_into_array(array, len, final_line);
	return (array);
}
