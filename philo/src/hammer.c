/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hammer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:12:47 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/28 16:36:10 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_hammer(t_philo *philo)
{
	philo->data->dead = -1;
	usleep((philo->data->time_to_die - philo->time_since_last_meal));
	ft_display(philo, DIE);
	pthread_mutex_unlock(philo->data->is_it_dead);
}

int	guardian_of_the_dead(t_philo *philo)
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
	pthread_mutex_unlock(philo->data->is_it_dead);
	return (0);
}
