/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_nb_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:38:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/01 19:51:29 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif_nb_argc(int argc, char **argv)
{
	char	**tab;
	int		i;

	if (argc <= 1)
		return ;
	i = 0;
	else if (argc == 2)
	{
		tab = ft_split(argv[1], " ");
		while (tab[i])
			check_error(tab[i++]);
	}
	else
		while (argv[i])
			check_error(argv[i++]);
}
