/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thanatos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:29:16 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/26 18:47:01 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thanatos_sleeper(t_philo *philo)
{
	if (philo->data->dead == -1)
		return (1);
	if (philo->data->time_to_die < philo->data->time_to_sleep)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
			check_if(ERROR_THREAD);
		philo->data->dead = -1;
		ft_display(philo, DIE);
		return (1);
	}
	return (0);
}

int	ft_thanatos_eater(t_philo *philo)
{
	if (philo->data->dead == -1)
		return (1);
	if (philo->data->time_to_die < philo->data->time_to_eat)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
			check_if(ERROR_THREAD);
		philo->data->dead = -1;
		ft_display(philo, DIE);
		return (1);
	}
	return (0);
}

int	ft_thanatos_master(t_philo *philo)
{
	if (philo->last_meal == 0)
		philo->time_since_last_meal = 0;
	else
		philo->time_since_last_meal = (get_time() - philo->last_meal) * 1000;
	if (philo->data->dead == -1)
		return (1);
	if (philo->time_since_last_meal > philo->data->time_to_die)
	{
		if (pthread_mutex_lock(philo->data->is_it_dead) == -1)
			check_if(ERROR_THREAD);
		philo->data->dead = -1;
		ft_display(philo, DIE);
		return (1);
	}
	return (0);
}