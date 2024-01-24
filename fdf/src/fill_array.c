/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:45 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/24 16:42:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stray	*split_array(t_stray *array, size_t len, size_t len_total)
{
	size_t	i;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	i = 0;
	while (i < len_total)
	{

	}
}

t_stray	*fill_array(char *final_line, size_t len)
{
	t_stray	*array;
	size_t	len_total;

	len_total = ft_count_words(final_line, 32);
	array = split_array(array, len, len_total);
	ft_printf("%s\n", final_line);
	printf("%ld\n", len);
	return (array);
}
