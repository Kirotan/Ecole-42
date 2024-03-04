/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:00:57 by gdoumer           #+#    #+#             */
/*   Updated: 2024/03/04 11:29:47 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->own_fork) == -1)
	{
		check_if(ERROR_THREAD);
		return (1);
	}
	if (ft_thanatos_master(philo) == 1)
	{
		give_way_fork(philo);
		return (1);
	}
	if (guardian_of_the_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->own_fork);
		return (1);
	}
	ft_display(philo, FORK);
	take_fork_2(philo);
	return (0);
}

int	take_fork_2(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) == -1)
	{
		pthread_mutex_unlock(philo->own_fork);
		check_if(ERROR_THREAD);
		return (1);
	}
	if (ft_thanatos_master(philo) == 1)
	{
		give_way_fork(philo);
		return (1);
	}
	if (guardian_of_the_dead(philo) == 1)
	{
		give_way_fork(philo);
		return (1);
	}
	ft_display(philo, FORK);
	return (0);
}

int	give_way_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (guardian_of_the_dead(philo) == 1)
		return (1);
	return (0);
}
