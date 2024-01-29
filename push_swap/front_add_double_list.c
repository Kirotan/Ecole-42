/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_add_double_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:31:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 18:10:16 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	front_add_double_list(t_dlist **double_list, t_dlist *new)
{
	if (!*double_list)
	{
		*double_list = new;
		new->dl_prev = new;
		new->dl_next = new;
	}
	else
	{
		new->dl_prev = (*double_list)->dl_prev;
		new->dl_next = *double_list;
		new->dl_prev->dl_next = new;
		(*double_list)->dl_prev = new;
		*double_list = new;
	}
}
