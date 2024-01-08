/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/08 18:47:39 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*dl_a;
	t_dlist	*dl_b;

	check_error(argc, argv);
	dl_a = initialize_double_list(argc, argv);
	dl_b = NULL;
	create_index(&dl_a, length_double_list(&dl_a));
	algorithm(argc -1, &dl_a, &dl_b);

	push_b(&dl_a, &dl_b);
	push_b(&dl_a, &dl_b);
	push_b(&dl_a, &dl_b);
	sort_three_b(&dl_b);
	test_print(dl_a);
	ft_printf("\n");
	test_print(dl_b);
	return (0);
}
