/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 23:33:33 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_index(t_dlist *stack)
{
	t_dlist	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp->dl_next != stack)
	{
		printf("value: %ld, index: %ld\n", tmp->data, tmp->index);
		tmp = tmp->dl_next;
	}
	printf("value: %ld, index: %ld\n", tmp->data, tmp->index);
	return ;
}

int	main(int argc, char **argv)
{
	t_dlist	*dl_a;
//	t_dlist	*dl_b;

	check_error(argc, argv);
	dl_a = initialize_double_list(argc, argv);
//	dl_b = NULL;
	create_index(&dl_a, length_double_list(&dl_a));
	print_stack_index(dl_a);
	return (0);
}
