/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:10:12 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 16:43:27 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_list_seven(t_dlist **dl_a, t_dlist **dl_b, size_t index_pos)
{
	size_t	j;

	j = 0;
	while (j < 7)
	{
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
		if (j > 1 && length_double_list(dl_b) > 1)
			if ((*dl_b)->index < (*dl_b)->dl_next->index)
				swap_b(dl_b);
	}
}

void	sort_seven(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	tmp_a;

	index_pos = 1;
	tmp_a = length_double_list(dl_a);
	while (index_pos < tmp_a)
	{
		change_list_seven(dl_a, dl_b, index_pos);
		index_pos = index_pos + 7;
	}
}
