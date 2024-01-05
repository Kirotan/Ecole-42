/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:35 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 17:16:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct double_list_chain
{
	long						data;
	size_t						index;
	struct double_list_chain	*dl_prev;
	struct double_list_chain	*dl_next;
}	t_dlist;

void	check_error(int argc, char **argv);
int		generate_message_error(void);
t_dlist	*initialize_double_list(int argc, char **argv);
t_dlist	*new_double_list(long number);
void	back_add_double_list(t_dlist **double_list, t_dlist *new);
size_t	length_double_list(t_dlist **dl_a);

#endif
