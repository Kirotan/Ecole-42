/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:50 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/16 13:27:39 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push_swap()
{
	int	l;

	l = 1;
	l = l + 1;
}

int	main(int argc, char **argv)
{
	dbl_list	a;
	dbl_list	b;
	int			nb_argc;

	if (argc == 1)
		return (0);
	nb_argc = count_argc(argv);
	a = fill_list(**a, nb_argc, argv);
	return (0);
}
