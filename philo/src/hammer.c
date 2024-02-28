/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hammer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:12:47 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/28 15:17:24 by gdoumer          ###   ########.fr       */
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
