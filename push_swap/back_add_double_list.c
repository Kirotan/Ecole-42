/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_add_double_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:57:26 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 17:42:04 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_add_double_list(t_dlist **double_list, t_dlist *new)
{
	t_dlist	*last;

	if (!double_list)
		return ;
	if (!*double_list)
		*double_list = new;
	else
	{
		last = (*double_list)->dl_prev;
		last->dl_next = new;
		new->dl_prev = last;
		new->dl_next = *double_list;
		(*double_list)->dl_prev = new;
	}
}
