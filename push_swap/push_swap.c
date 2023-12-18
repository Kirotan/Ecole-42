/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:50 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/18 17:07:51 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push_swap()
{
}

int	main(int argc, char **argv)
{
	dbl_list	a;
	dbl_list	b;
	int			nb_words;

	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		nb_words = count_words(argv[1]);
		a.quelquechose = ft_split(argv[1], ' ');
		error_or_not(nb_words, a);
	}
	if (argc > 2)
	{
		error_or_not(argc, argv);
	}
	return (0);
}
