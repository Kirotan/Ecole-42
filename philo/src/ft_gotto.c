/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:48 by gdoumer           #+#    #+#             */
/*   Updated: 2024/03/04 13:43:50 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dionysos(t_philo *philo)
{
	if (ft_thanatos_master(philo) == 1)
		return (1);
	if (ft_thanatos_eater(philo) == 1)
		return (1);
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	ft_display(philo, EAT);
	philo->last_meal = get_time();
	philo->nb_meal_eaten--;
	usleep(philo->data->time_to_eat);
	return (0);
}

int	ft_athena(t_philo *philo)
{
	if (ft_thanatos_master(philo) == 1)
		return (1);
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	if (philo->data->nb_philo % 2 == 1)
	{
		if (ft_thanatos_thinker(philo) == 1)
			return (1);
		usleep(philo->data->time_to_eat);
	}
	ft_display(philo, THINK);
	return (0);
}

int	ft_morphe(t_philo *philo)
{
	if (ft_thanatos_master(philo) == 1)
		return (1);
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	ft_display(philo, SLEEP);
	if (guardian_of_the_dead(philo) == 0 && philo->time_since_last_meal
		+ philo->data->time_to_sleep > philo->data->time_to_die)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
		{
			check_if(ERROR_THREAD);
			return (1);
		}
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		ft_hammer(philo);
		return (1);
	}
	else
		usleep(philo->data->time_to_sleep);
	return (0);
}
