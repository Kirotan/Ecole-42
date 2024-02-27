/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:48 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/27 16:29:10 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->data->dead == -1)
		return (1);
	if (pthread_mutex_lock(philo->own_fork) == -1)
	{
		check_if(ERROR_THREAD);
		return (1);
	}
	if (philo->data->dead == -1)
		return (1);
	ft_display(philo, FORK);
	if (pthread_mutex_lock(philo->left_fork) == -1)
	{
		check_if(ERROR_THREAD);
		return (1);
	}
	if (philo->data->dead == -1)
		return (1);
	ft_display(philo, FORK);
	return (0);
}

void	give_way_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	ft_dionysos(t_philo *philo)
{
	if (ft_thanatos_master(philo) == 1)
		return (1);
	if (ft_thanatos_eater(philo) == 1)
		return (1);
	if (philo->data->dead == -1)
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
	if (philo->data->dead == -1)
		return (1);
	ft_display(philo, THINK);
	return (0);
}

int	ft_morphe(t_philo *philo)
{
	if (ft_thanatos_master(philo) == 1)
		return (1);
	if (ft_thanatos_sleeper(philo) == 1)
		return (1);
	if (philo->data->dead == -1)
		return (1);
	ft_display(philo, SLEEP);
	if (philo->time_since_last_meal
		+ philo->data->time_to_sleep > philo->data->time_to_die)
	{
		philo->data->dead = -1;
		usleep((philo->data->time_to_die - philo->time_since_last_meal) - 1000);
		ft_display(philo, DIE);
		return (1);
	}
	else
		usleep(philo->data->time_to_sleep);
	return (0);
}
