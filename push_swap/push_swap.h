/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:13:19 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/01 18:29:42 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct double_list_chained
{
	size_t						length;
	struct double_list_chained	*lst_head;
	struct double_list_chained	*lst_tail;
}	dlist;

typedef struct p_node
{
	int				data;
	struct p_node	*p_prev;
	struct p_node	*p_next;
}	node;

#endif
