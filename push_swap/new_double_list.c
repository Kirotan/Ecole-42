/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_double_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:28:20 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/04 16:14:13 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new_double_list(long number)
{
	t_dlist	*node;

	node = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	node->data = number;
	node->dl_prev = node;
	node->dl_next = node;
	return (node);
}
