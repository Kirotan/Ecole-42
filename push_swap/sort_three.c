/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:41:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/08 14:45:06 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_dlist **dl_a)
{
	if ((*dl_a)->index == 3)
		rotate_a(dl_a);
	if ((*dl_a)->index == 2 && (*dl_a)->dl_next->index == 1)
		swap_a(dl_a);
	if ((*dl_a)->dl_next->index == 3 && (*dl_a)->index == 2)
		reverse_a(dl_a);
	if ((*dl_a)->dl_next->index == 3 && (*dl_a)->index == 1)
	{
		reverse_a(dl_a);
		swap_a(dl_a);
	}

}

void	sort_three_b(t_dlist **dl_b)
{
	if ((*dl_b)->index == 3)
		rotate_b(dl_b);
	if ((*dl_b)->index == 2 && (*dl_b)->dl_next->index == 1)
		swap_b(dl_b);
	if ((*dl_b)->dl_next->index == 3 && (*dl_b)->index == 2)
		reverse_b(dl_b);
	if ((*dl_b)->dl_next->index == 3 && (*dl_b)->index == 1)
	{
		reverse_b(dl_b);
		swap_a(dl_b);
	}
}
