/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:03 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/28 14:20:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_routine(t_philo *philo)
{
	while (philo->nb_meal_eaten > 0)
	{
		if (take_fork(philo) == 1)
			return (1);
		if (ft_dionysos(philo) == 1)
		{
			give_way_fork(philo);
			return (1);
		}
		if (give_way_fork(philo) == 1)
			return (1);
		if (ft_morphe(philo) == 1)
			return (1);
		if (ft_athena(philo) == 1)
			return (1);
	}
	return (0);
}

static int	best_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (ft_routine(philo) == 1)
			return (1);
	}
	else
	{
		usleep(1500);
		if (ft_routine(philo) == 1)
			return (1);
	}
	return (0);
}

int	mechanism(t_philo *philo)
{
	int	i;

	i = 0;
	philo[0].data->start_time = get_time();
	while (i < philo[0].data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)best_life,
				&philo[i]) != 0)
		{
			while (i > 0)
				pthread_join(philo[i--].thread, NULL);
			return (1);
		}
		i++;
	}
	i = -1;
	while (++i < philo[0].data->nb_philo)
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (1);
	return (0);
}
