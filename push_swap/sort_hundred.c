/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 16:49:47 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rest_of_a(t_dlist **dl_a)
{
	if (length_double_list(dl_a) == 2)
		sort_two_a(dl_a);
	if (length_double_list(dl_a) == 3)
		sort_three_a(dl_a);
}

static void	handle_case(t_dlist	**dl_a, t_dlist **dl_b)
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
}

static void	change_list(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	j;

	j = 0;
	while (j < 3)
	{
		if (length_double_list(dl_a) == 4 && (j == 0 || j == 1))
			while ((*dl_a)->index != index_pos)
				rotate_a(dl_a);
		if (length_double_list(dl_a) <= 3)
		{
			rest_of_a(dl_a);
			break ;
		}
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2)
		{
			handle_case(dl_a, dl_b);
			j++;
		}
		else if (ft_position(dl_a, index_pos) == 0)
			reverse_a(dl_a);
		else if (ft_position(dl_a, index_pos) == 1)
			rotate_a(dl_a);
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
