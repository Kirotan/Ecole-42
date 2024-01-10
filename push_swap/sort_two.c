/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:31:20 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/10 18:10:32 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_dlist **dl_a)
{
	if ((*dl_a)->index > (*dl_a)->dl_next->index)
		swap_a(dl_a);
	else
		return ;
}

void	sort_two_b(t_dlist **dl_b)
{
	if ((*dl_b)->index < (*dl_b)->dl_next->index)
		swap_b(dl_b);
	else
		return ;
}
