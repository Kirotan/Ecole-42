/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:36:15 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/27 18:43:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	freeing_machine_loop(t_philo *philo, int i)
{
	while (i > 0)
	{
		pthread_mutex_destroy(philo[i].own_fork);
		free(philo[i].own_fork);
		i--;
	}
	pthread_mutex_destroy(philo->data->is_it_dead);
	pthread_mutex_destroy(philo->data->write_dead);
	free(philo->data->is_it_dead);
	free(philo->data->write_dead);
	free(philo);
	return (1);
}

int	freeing_machine(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(philo[i].own_fork);
		free(philo[i].own_fork);
		i++;
	}
	pthread_mutex_destroy(philo->data->is_it_dead);
	pthread_mutex_destroy(philo->data->write_dead);
	free(philo->data->is_it_dead);
	free(philo->data->write_dead);
	free(philo);
	return (1);
}
