/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:25 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/21 14:08:29 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error : wrong number of arguments.\n");
		return (1);
	}
	return (0);
}

static int	check_argv(int argc, char **argv)
{
	long	tmp;

	while (argc > 1)
	{
		tmp = ft_atol(argv[argc - 1]);
		if (tmp <= 0 || tmp > INT_MAX)
		{
			printf("Error : wrong argument. Only number.\n");
			return (1);
		}
		argc--;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	if (check_argc(argc) == 1)
		return (1);
	if (check_argv(argc, argv) == 1)
		return (1);
	return (0);
}
