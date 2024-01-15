/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:41:26 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/15 18:04:22 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_double_list(t_dlist **double_list)
{
	t_dlist	*tmp;

	tmp = (*double_list)->dl_next;
	(*double_list)->dl_next = tmp->dl_next;
	tmp->dl_next->dl_prev = tmp->dl_prev;
	front_add_double_list(double_list, tmp);
}

void	swap_both(t_dlist **dl_a, t_dlist **dl_b)
{
	if (*dl_a && *dl_b)
	{
		swap_double_list(dl_a);
		swap_double_list(dl_b);
	}
	ft_printf("ss\n");
}

void	swap_b(t_dlist **dl_b)
{
	if (*dl_b)
		swap_double_list(dl_b);
	ft_printf("sb\n");
}

void	swap_a(t_dlist **dl_a)
{
	if (*dl_a)
		swap_double_list(dl_a);
	ft_printf("sa\n");
}
