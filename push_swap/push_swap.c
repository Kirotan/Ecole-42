/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:50 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/20 10:00:49 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**tab;
	dbl_list	a;
	dbl_list	b;
	int			nb_words;

	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		nb_words = count_words(argv[1]);
		tab = ft_split(argv[1], ' ');
		error_or_not(nb_words, tab);
		
	}
	if (argc > 2)
	{
		nb_words = argc - 1;
		error_or_not(nb_words, argv);
	}
	return (0);
}
