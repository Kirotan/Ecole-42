/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:35 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 16:35:24 by gdoumer          ###   ########.fr       */
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

void	test_print(t_dlist *dl_a);
void	check_error(int argc, char **argv);
int		generate_message_error(void);
t_dlist	*initialize_double_list(int argc, char **argv);
t_dlist	*new_double_list(long number);
void	front_add_double_list(t_dlist **double_list, t_dlist *new);
void	back_add_double_list(t_dlist **double_list, t_dlist *new);
size_t	length_double_list(t_dlist **dl_a);
void	create_index(t_dlist **dl_a, size_t index);
void	swap_a(t_dlist **dl_a);
void	swap_b(t_dlist **dl_b);
void	swap_both(t_dlist **dl_a, t_dlist **dl_b);
void	rotate_a(t_dlist **dl_a);
void	rotate_b(t_dlist **dl_b);
void	rotate_both(t_dlist **dl_a, t_dlist **dl_b);
void	reverse_a(t_dlist **dl_a);
void	reverse_b(t_dlist **dl_b);
void	reverse_both(t_dlist **dl_a, t_dlist **dl_b);
void	push_a(t_dlist **dl_a, t_dlist **dl_b);
void	push_b(t_dlist **dl_a, t_dlist **dl_b);
void	delete_node(t_dlist **double_list, t_dlist *node_to_delete);
void	algorithm(int nb_param, t_dlist **dl_a, t_dlist **dl_b);
void	sort_two_a(t_dlist **dl_a);
void	sort_two_b(t_dlist **dl_b);
void	sort_three_a(t_dlist **dl_a);
void	sort_three_b(t_dlist **dl_b);
void	sort_five(t_dlist **dl_a, t_dlist **dl_b, int nb_param);
void	sort_seven(t_dlist **dl_a, t_dlist **dl_b);
void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b);
void	sort_max(t_dlist **dl_a, t_dlist **dl_b);
int		ft_position(t_dlist **dl_a, size_t index_pos);
int		ft_position_max(t_dlist **dl_a, size_t index_pos);

#endif
