/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 19:24:54 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	duplication(int argc, char **argv)
{
	int	i;
	int	j;
	int	nb;
	int	tmp;

	i = 1;
	while (++i < argc)
	{
		j = 0;
		nb = ft_atoi(argv[i]);
		while (++j < argc)
		{
			tmp = ft_atoi(argv[j]);
			if (i == j && j < argc)
			{
				j++;
				tmp = ft_atoi(argv[j]);
			}
			if (nb == tmp)
			{
				generate_message_error();
				exit(EXIT_SUCCESS);
			}
		}
	}
}

static	void	is_it_number(char *argv)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!((argv[i] >= '0' && argv[i] <= '9')
				|| (argv[i] == '-' || argv[i] == '+')))
		{
			generate_message_error();
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	nb = ft_atol(argv);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		generate_message_error();
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	check_error(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return ;
	i = 1;
	while (i < argc)
		is_it_number(argv[i++]);
	duplication(argc, argv);
}
