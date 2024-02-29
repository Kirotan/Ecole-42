/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:36:15 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/29 21:26:31 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freeing_machine_loop(t_philo *philo, int i)
{
	while (i > 1)
	{
		pthread_mutex_destroy(philo[i].own_fork);
		free(philo[i].own_fork);
		i--;
	}
	free(philo[i - 1].own_fork);
	pthread_mutex_destroy(philo->data->is_it_dead);
	pthread_mutex_destroy(philo->data->write_dead);
	free(philo->data->is_it_dead);
	free(philo->data->write_dead);
	free(philo);
}

void	freeing_machine(t_philo *philo)
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
}
