/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 16:38:51 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



size_t	position_averag(t_dlist **dlist, size_t len_list, size_t index_position)
{
	size_t	x_one;
	size_t	y_two;
	size_t	z_three;
	size_t	average;
	size_t	i;

	i = 1;
	x_one = 0;
	y_two = 0;
	z_three = 0;
	while (i < len_list)
	{
		if ((*dlist)->index == index_position)
			x_one = i;
		if ((*dlist)->index == index_position + 1)
			y_two = i;
		if ((*dlist)->index == index_position + 2)
			z_three = i;
		(*dlist)->dl_next;
		i++;
	}
	average = (x_one + y_two + z_three) / 3;
	return (average);
}

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b, int nb_param)
{
	size_t	index_position;
	size_t	len_a;
	size_t	len_b;
	size_t	average;

	index_position = 1;
	len_a = 0;
	len_b = 0;
	average = 0;

}
