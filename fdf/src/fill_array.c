/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:45 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/24 19:28:48 by gdoumer          ###   ########.fr       */
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

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	c = 32;
	while (final_line[i])
	{
		ft_printf("test\n");
		if (final_line[i] == c)
			i++;
		if (final_line[i] != c && final_line[i])
		{
			start = i;
			while (final_line[i] && final_line[i] != c)
				i++;
			ft_printf("PP\n");
			char * temp = ft_substr(final_line, start, i - start);
			printf("Substr: %s\tJ=%ld\tlen=%zu\n", temp, j, len);
			array[j].z = ft_atoi(temp);
			ft_printf("OO\n");
			array[j].x = x;
			if (x == (int)len)
				x = 0;
			x++;
			array[j].y = y;
			if (x == (int)len)
				y++;
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
	printf("LEN TOTAL %ld\n", len_total );
	array = allocate_memory_stray(len_total);
	split_line_into_array(array, len, final_line);
	ft_printf("%s\n", final_line);
	printf("%ld\n", len);
	return (array);
}
