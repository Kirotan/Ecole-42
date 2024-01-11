/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:31:08 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 14:06:30 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_case_max(t_dlist	**dl_a, t_dlist **dl_b)
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

static void	change_list_max(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < 5)
	{
		if ((*dl_a)->index == index_pos || (*dl_a)->index == index_pos + 1
			|| (*dl_a)->index == index_pos + 2
			|| (*dl_a)->index == index_pos + 3
			|| (*dl_a)->index == index_pos + 4)
		{
			handle_case_max(dl_a, dl_b);
			i++;
			j++;
		}
		else if (ft_position_max(dl_a, index_pos) == 0)
			reverse_a(dl_a);
		else
			rotate_a(dl_a);
		i++;
	}
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
		index_pos = index_pos + 5;
	}
	tmp = length_double_list(dl_b);
	while (i < tmp)
	{
		push_a(dl_a, dl_b);
		i++;
	}
}
