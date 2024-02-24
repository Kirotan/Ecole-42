/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:49:03 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/24 17:29:23 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_routine(t_philo *philo)
{
	while (philo->nb_meal_eaten > 0)
	{
		take_fork(philo);
		ft_dionysos(philo);
		give_way_fork(philo);
		ft_morphe(philo);
		ft_athena(philo);
	}
}

static void	best_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_routine(philo);
	else
	{
		usleep(philo->data->time_to_eat / 2);
		ft_routine(philo);
	}
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
			check_if(ERROR_THREAD);
		i++;
	}
	i = 0;
	while (i < philo[0].data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			check_if(ERROR_THREAD);
		i++;
	}
	return (0);
}
