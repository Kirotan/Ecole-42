/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_averag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:05:08 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 17:08:55 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	position_averag(t_dlist **dlist, size_t len_list, size_t index_pos)
{
	size_t	x_one;
	size_t	y_two;
	size_t	z_three;
	size_t	average;
	size_t	i;

	if (!dlist || !*dlist || !len_list)
		return (0);
	i = 1;
	x_one = 0;
	y_two = 0;
	z_three = 0;
	while (i <= len_list)
	{
		if ((*dlist)->index == index_pos)
			x_one = i;
		if ((*dlist)->index == index_pos + 1)
			y_two = i;
		if ((*dlist)->index == index_pos + 2)
			z_three = i;
		(*dlist) = (*dlist)->dl_next;
		i++;
	}
	average = (x_one + y_two + z_three) / 3;
	return (average);
}
