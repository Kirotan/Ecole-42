/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:04:48 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/24 17:26:18 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->own_fork);
	ft_display(philo, FORK);
	pthread_mutex_lock(philo->left_fork);
	ft_display(philo, FORK);
}

void	give_way_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->own_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_dionysos(t_philo *philo)
{
	ft_display(philo, EAT);
	philo->nb_meal_eaten--;
	usleep(philo->data->time_to_eat);
}

void	ft_athena(t_philo *philo)
{
	ft_display(philo, THINK);
}

void	ft_morphe(t_philo *philo)
{
	ft_display(philo, SLEEP);
	usleep(philo->data->time_to_sleep);
}
