/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:08:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 15:44:42 by gdoumer          ###   ########.fr       */
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
	return (0);
}
