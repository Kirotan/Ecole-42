/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:41:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 12:50:00 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_dlist **dl_a)
{
	if ((*dl_a)->index < (*dl_a)->dl_next->index
		&& (*dl_a)->dl_next->index > (*dl_a)->dl_next->dl_next->index)
	{
		reverse_a(dl_a);
		swap_a(dl_a);
	}
	if ((*dl_a)->index > (*dl_a)->dl_next->index
		&& (*dl_a)->dl_next->index < (*dl_a)->dl_next->dl_next->index
		&& (*dl_a)->index < (*dl_a)->dl_prev->index)
		swap_a(dl_a);
	if ((*dl_a)->index < (*dl_a)->dl_next->index
		&& (*dl_a)->dl_next->index > (*dl_a)->dl_next->dl_next->index)
		reverse_a(dl_a);
	if ((*dl_a)->index > (*dl_a)->dl_next->index
		&& (*dl_a)->dl_next->index < (*dl_a)->dl_next->dl_next->index
		&& (*dl_a)->index > (*dl_a)->dl_prev->index)
		rotate_a(dl_a);
	if ((*dl_a)->index > (*dl_a)->dl_next->index
		&& (*dl_a)->dl_next->index > (*dl_a)->dl_next->dl_next->index)
	{
		swap_a(dl_a);
		reverse_a(dl_a);
	}
}

void	sort_three_b(t_dlist **dl_b)
{
	if ((*dl_b)->index > (*dl_b)->dl_next->index
		&& (*dl_b)->dl_next->index < (*dl_b)->dl_next->dl_next->index)
	{
		reverse_b(dl_b);
		swap_b(dl_b);
	}
	if ((*dl_b)->index < (*dl_b)->dl_next->index
		&& (*dl_b)->dl_next->index > (*dl_b)->dl_next->dl_next->index
		&& (*dl_b)->index > (*dl_b)->dl_prev->index)
		swap_b(dl_b);
	if ((*dl_b)->index > (*dl_b)->dl_next->index
		&& (*dl_b)->dl_next->index < (*dl_b)->dl_next->dl_next->index)
		reverse_b(dl_b);
	if ((*dl_b)->index < (*dl_b)->dl_next->index
		&& (*dl_b)->dl_next->index > (*dl_b)->dl_next->dl_next->index
		&& (*dl_b)->index < (*dl_b)->dl_prev->index)
		rotate_b(dl_b);
	if ((*dl_b)->index < (*dl_b)->dl_next->index
		&& (*dl_b)->dl_next->index < (*dl_b)->dl_next->dl_next->index)
	{
		swap_b(dl_b);
		reverse_b(dl_b);
	}
}
