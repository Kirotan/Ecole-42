/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:43:03 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/06 22:17:35 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_first(t_dlist **double_list)
{
	*double_list = (*double_list)->dl_next;
}

void	rotate_both(t_dlist **dl_a, t_dlist **dl_b)
{
	if (*dl_a && *dl_b)
	{
		change_first(dl_a);
		change_first(dl_b);
	}
	ft_printf("rr\n");
}

void	rotate_b(t_dlist **dl_b)
{
	if (*dl_b)
		change_first(dl_b);
	ft_printf("rb\n");
}

void	rotate_a(t_dlist **dl_a)
{
	if (*dl_a)
		change_first(dl_a);
	ft_printf("ra\n");
}
