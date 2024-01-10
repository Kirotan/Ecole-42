/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/10 18:00:54 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rest_of_b(t_dlist **dl_a, t_dlist **dl_b)
{
	if (length_double_list(dl_b) == 2)
	{
		sort_two_b(dl_b);
		return (0);
	}
	if (length_double_list(dl_b) == 3)
	{
		sort_three_b(dl_b);
		return (0);
	}
	if (length_double_list(dl_a) == 2)
	{
		sort_two_a(dl_a);
		return (1);
	}
	if (length_double_list(dl_a) == 3)
	{
		sort_three_a(dl_a);
		return (1);
	}
	return (0);
}

void	rotate_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	size_t	j;
	int		sort_or_not;

	i = 0;
	j = 0;
	while (i < length_double_list(dl_a))
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			push_b(dl_a, dl_b);
			if ((*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
			sort_or_not = rest_of_b(dl_a, dl_b);
			if (sort_or_not == 1)
				return ;
			i++;
			j++;
			if (j > 2)
				break ;
			if (j < 4)
				continue ;
		}
		i++;
		rotate_a(dl_a);
	}
}

void	reverse_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	size_t	j;
	int		sort_or_not;

	i = 0;
	j = 0;
	while (i < length_double_list(dl_a))
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			push_b(dl_a, dl_b);
			sort_or_not = rest_of_b(dl_a, dl_b);
			if (sort_or_not == 1)
				return ;
			i++;
			j++;
			if (j > 3)
				break ;
			if (j < 3)
				continue ;
		}
		i++;
		reverse_a(dl_a);
	}
}

void	fill_b(t_dlist **dl_a, t_dlist **dl_b, size_t aver_a, size_t index_pos)
{
	if (aver_a >= length_double_list(dl_a) / 2)
	{
		reverse_list(dl_a, dl_b, index_pos);
	}
	else if (aver_a < length_double_list(dl_a) / 2)
	{
		rotate_list(dl_a, dl_b, index_pos);
	}
}

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	aver_a;
	size_t	tmp;
	size_t	i;

	i = 0;
	index_pos = 1;
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
