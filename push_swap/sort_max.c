/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:31:08 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 19:11:30 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_sort_max(t_dlist **dl_a, t_dlist **dl_b, size_t *i)
{
	while (*i < 6)
	{
		if ((*dl_b)->index > (*dl_b)->dl_next->index)
		{
			push_a(dl_a, dl_b);
			(*i)++;
		}
		if ((*dl_b)->index < (*dl_b)->dl_next->index)
			swap_b(dl_b);
	}
	while (*i != 1)
	{
		if ((*dl_a)->index > (*dl_a)->dl_next->index)
			swap_a(dl_a);
		if ((*dl_a)->index < (*dl_a)->dl_next->index)
		{
			push_b(dl_a, dl_b);
			(*i)--;
		}
	}
	push_b(dl_a, dl_b);
}

static void	change_list_max(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	j;
	size_t	i;
	size_t	k;
	size_t	p;

	j = 0;
	i = 0;
	k = 0;
	p = 0;
	while (j < 7 || p < length_double_list(dl_a))
	{
		if (j > 1 && length_double_list(dl_b) > 1)
			if ((*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2
			|| (*dl_a)->index == index_pos + 3
			|| (*dl_a)->index == index_pos + 4
			|| (*dl_a)->index == index_pos + 5
			|| (*dl_a)->index == index_pos + 6)
		{
			push_b(dl_a, dl_b);
			j++;
		}
		else if (ft_position_max(dl_a, index_pos) == 0)
			reverse_a(dl_a);
		else if (ft_position_max(dl_a, index_pos) == 1)
			rotate_a(dl_a);
		p++;
	}
	while (k++ < 4)
		loop_sort_max(dl_a, dl_b, &i);
}

void	sort_max(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	tmp;
	size_t	i;

	i = 0;
	index_pos = 1;
	tmp = length_double_list(dl_a);
	while (index_pos < tmp)
	{
		change_list_max(dl_a, dl_b, index_pos);
		index_pos = index_pos + 7;
	}
	tmp = length_double_list(dl_b);
	while (i < tmp)
	{
		push_a(dl_a, dl_b);
		i++;
	}
}
