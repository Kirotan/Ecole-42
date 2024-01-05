/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_double_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:20:49 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/04 19:30:28 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*initialize_double_list(int argc, char **argv)
{
	t_dlist	*list_of_number;
	long	tmp;
	int		i;

	list_of_number = NULL;
	tmp = 0;
	i = 1;
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		back_add_double_list(&list_of_number, new_double_list(tmp));
		i++;
	}
	return (list_of_number);
}
