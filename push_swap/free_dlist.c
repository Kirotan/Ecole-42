/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:12:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/17 15:06:42 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dlist(t_dlist **double_list)
{
	t_dlist	*tmp;

	if (*double_list)
	{
		(*double_list)->dl_prev->dl_next = NULL;
		tmp = *double_list;
		while (*double_list)
		{
			tmp = (*double_list)->dl_next;
			free (*double_list);
			*double_list = tmp;
		}
		*double_list = NULL;
	}
}
