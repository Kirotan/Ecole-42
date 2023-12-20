/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:02:24 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/20 17:37:28 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

dbl_list	*ft_lstnew(void *content)
{
	dbl_list	*new;

	new = malloc(sizeof(dbl_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->cost = content;
	new->index = content;
	new->top_middle = content;
	new->cheapest = content;
	new->target_node = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}


