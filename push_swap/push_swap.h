/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:35 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/02 17:51:46 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct double_list_chain
{
	size_t						lenght;
	struct double_list_chain	*dl_head;
	struct double_list_chain	*dl_tail;
}	t_dlist;

typedef struct node_for_dbl_list_chain
{
	int								data;
	struct node_for_dbl_list_chain	*n_prev;
	struct node_for_dbl_list_chain	*n_next;
}	t_node;

#endif