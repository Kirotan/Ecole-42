/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/10 19:41:41 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rest_of_b(t_dlist **dl_b)
{
	if (length_double_list(dl_b) == 2)
		sort_two_b(dl_b);
	else if (length_double_list(dl_b) == 3)
		sort_three_b(dl_b);
}

void	change_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			if ((*dl_b) && (*dl_b)->dl_next != *dl_b
				&& (*dl_a)->index < (*dl_b)->index
				&& (*dl_a)->index < (*dl_b)->dl_next->index)
			{
				rotate_b(dl_b);
				push_b(dl_a, dl_b);
				swap_b(dl_b);
				reverse_b(dl_b);
			}
			else
				push_b(dl_a, dl_b);
			if ((*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
			i++;
			j++;
			if (j == 3)
				rest_of_b(dl_b);
		}
		else if (ft_position(dl_a, index_pos) == 0)
			reverse_a(dl_a);
		else
			rotate_a(dl_a);
		i++;
	}
}

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	tmp;
	size_t	i;

	i = 0;
	index_pos = 1;
	tmp = length_double_list(dl_a);
	while (index_pos < tmp)
	{
		change_list(dl_a, dl_b, index_pos);
		index_pos = index_pos + 3;
	}
	tmp = length_double_list(dl_b);
	while (i < tmp)
	{
		push_a(dl_a, dl_b);
		i++;
	}
}
