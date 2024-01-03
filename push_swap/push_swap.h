/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:35 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/03 14:35:02 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

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

void	check_error(int argc, char **argv);
int		generate_message_error(void);

#endif
