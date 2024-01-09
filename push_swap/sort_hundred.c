/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 19:04:45 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rest_of_b(t_dlist **dl_a, t_dlist **dl_b)
{
	if (length_double_list(dl_b) == 2)
	{
		sort_two_a(dl_a);
		return (1);
	}
	if (length_double_list(dl_b) == 3)
	{
		sort_three_a(dl_a);
		return (1);
	}
	return (0);
}

void	rotate_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	int		sort_or_not;

	i = 0;
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
			sort_or_not = rest_of_b(dl_a, dl_b);
			if (sort_or_not == 2 || sort_or_not == 3)
				return ;
			if (i > 3)
				break ;
		}
		rotate_a(dl_a);
		i++;
	}
}

void	reverse_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	int		sort_or_not;

	i = 0;
	while (length_double_list(dl_a) > i)
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			push_b(dl_a, dl_b);
			if (length_double_list(dl_b) > 1
				&& (*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
			i++;
			sort_or_not = rest_of_b(dl_a, dl_b);
			if (sort_or_not == 2 || sort_or_not == 3)
				return ;
			if (i > 3)
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
	size_t	tmp;
	size_t	i;

	i = 0;
	index_pos = 0;
	tmp = length_double_list(dl_a);
	while (index_pos < tmp)
	{
		aver_a = position_averag(dl_a, length_double_list(dl_a), index_pos);
		fill_b(dl_a, dl_b, aver_a, index_pos);
		index_pos = index_pos + 3;
	}
	tmp = length_double_list(dl_b);
	while (i < tmp)
	{
		push_a(dl_a, dl_b);
		i++;
	}
}
