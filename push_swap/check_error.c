/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:23:13 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/20 16:21:46 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplication(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (ft_printf("Error\n"));
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(char *str)
{
	int	i;
	int	nb;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || (str[i] != '+') || (str[i] != '-'))
			return (ft_printf("Error\n"));
		i++;
	}
	nb = ft_atoi(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (ft_printf("Error\n"));
	return (1);
}

int	error_or_not(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		check_error(argv[i]);
		i++;
	}
	check_duplication(argc, argv)
	return (1);
}
