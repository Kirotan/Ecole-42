/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/06 22:12:55 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_last(t_dlist **double_list)
{
	*double_list = (*double_list)->dl_prev;
}

void	reverse_both(t_dlist **dl_a, t_dlist **dl_b)
{
	if (*dl_a && *dl_b)
	{
		change_last(dl_a);
		change_last(dl_b);
	}
	ft_printf("rrr\n");
}

void	reverse_b(t_dlist **dl_b)
{
	if (*dl_b)
		change_last(dl_b);
	ft_printf("rrb\n");
}

void	reverse_a(t_dlist **dl_a)
{
	if (*dl_a)
		change_last(dl_a);
	ft_printf("rra\n");
}
