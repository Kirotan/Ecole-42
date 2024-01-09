/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 18:33:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;

	i = 1;
	while (i < length_double_list(dl_a))
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			push_b(dl_a, dl_b);
			if (length_double_list(dl_b) > 1
				&& (*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
			i++;
			if (i >= length_double_list(dl_a))
				break ;
		}
		rotate_a(dl_a);
		i++;
	}
}

void	reverse_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;

	i = 1;
	while (i < length_double_list(dl_a))
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			push_b(dl_a, dl_b);
			if (length_double_list(dl_b) > 1
				&& (*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
			i++;
			if (i >= length_double_list(dl_a))
				break ;
		}
		reverse_a(dl_a);
		i++;
	}
}

void	fill_b(t_dlist **dl_a, t_dlist **dl_b, size_t aver_a, size_t index_pos)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (aver_a > length_double_list(dl_a) / 2)
		{
			reverse_list(dl_a, dl_b, index_pos);
		}
		else if (aver_a < length_double_list(dl_a) / 2)
		{
			rotate_list(dl_a, dl_b, index_pos);
		}
		i++;
		index_pos++;
	}
}

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	aver_a;
//	size_t	aver_b;

	index_pos = 0;
	while (index_pos < length_double_list(dl_a))
	{
		aver_a = position_averag(dl_a, length_double_list(dl_a), index_pos);
		fill_b(dl_a, dl_b, aver_a, index_pos);
		index_pos = index_pos + 3;
	}
}
