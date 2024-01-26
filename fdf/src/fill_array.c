/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:45 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 15:51:13 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	extract_and_convert(char *final_line, size_t *start, size_t *i)
{
	char	*temp;
	int		result;

	temp = ft_substr(final_line, *start, *i - *start);
	result = ft_atoi(temp);
	free(temp);
	return (result);
}

void	increment_coordinates(int *x, int *y, int len)
{
	if (*x + 1 == len)
		(*y)++;
	if (*x + 1 == len)
		*x = -1;
	(*x)++;
}

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
	size_t			i;
	size_t			start;
	char			c;
	t_coordinates	coords;

	i = 0;
	c = 32;
	coords.j = 0;
	coords.x = 0;
	coords.y = 0;
	while (final_line[i])
	{
		if (final_line[i] == c)
			i++;
		if (final_line[i] != c && final_line[i])
		{
			start = i;
			while (final_line[i] && final_line[i] != c)
				i++;
			array[coords.j].z = extract_and_convert(final_line, &start, &i);
			array[coords.j].x = coords.x;
			array[coords.j].y = coords.y;
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

	len_total = ft_count_words(final_line, 32);
	array = allocate_memory_stray(len_total);
	split_line_into_array(array, len, final_line);
	return (array);
}
