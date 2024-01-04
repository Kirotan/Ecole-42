/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_double_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:20:49 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/04 16:10:55 by gdoumer          ###   ########.fr       */
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

		i++;
	}
}
