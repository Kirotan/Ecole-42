/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thanatos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:29:16 by gdoumer           #+#    #+#             */
/*   Updated: 2024/03/04 13:19:00 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thanatos_thinker(t_philo *philo)
{
	if (ft_thanatos_thinker_0(philo) == 1)
		return (1);
	if (philo->time_since_last_meal + philo->data->time_to_eat
		> philo->data->time_to_die)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
		{
			check_if(ERROR_THREAD);
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		philo->data->dead = -1;
		pthread_mutex_unlock(philo->data->is_it_dead);
		usleep(philo->data->time_to_die - philo->time_since_last_meal);
		ft_display(philo, DIE);
		return (1);
	}
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	return (0);
}

int	ft_thanatos_thinker_0(t_philo *philo)
{
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	if (philo->last_meal == 0)
		philo->time_since_last_meal = 0;
	else
		philo->time_since_last_meal = (get_time() - philo->last_meal) * 1000;
	return (0);
}

int	ft_thanatos_eater(t_philo *philo)
{
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	if (philo->data->time_to_die < philo->data->time_to_eat)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
		{
			check_if(ERROR_THREAD);
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		philo->data->dead = -1;
		pthread_mutex_unlock(philo->data->is_it_dead);
		usleep(philo->data->time_to_die);
		ft_display(philo, DIE);
		return (1);
	}
	return (0);
}

int	ft_thanatos_master(t_philo *philo)
{
	ft_thanatos_thinker_0(philo);
	if (philo->time_since_last_meal > philo->data->time_to_die)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
		{
			check_if(ERROR_THREAD);
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		if (philo->data->dead == -1)
		{
			pthread_mutex_unlock(philo->data->is_it_dead);
			return (1);
		}
		philo->data->dead = -1;
		pthread_mutex_unlock(philo->data->is_it_dead);
		ft_display(philo, DIE);
		return (1);
	}
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	return (0);
}
