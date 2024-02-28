/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotto_odd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:37 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/28 15:54:17 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork_odd(t_philo *philo)
{
	if (philo->data->dead == -1)
		return (1);
	if (pthread_mutex_lock(philo->left_fork) == -1)
	{
		check_if(ERROR_THREAD);
		return (1);
	}
	if (philo->data->dead == -1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	ft_display(philo, FORK);
	if (pthread_mutex_lock(philo->own_fork) == -1)
	{
		check_if(ERROR_THREAD);
		return (1);
	}
	if (philo->data->dead == -1)
	{
		give_way_fork(philo);
		return (1);
	}
	ft_display(philo, FORK);
	return (0);
}

int	give_way_fork_odd(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->own_fork);
	if (philo->data->dead == -1)
		return (1);
	return (0);
}
