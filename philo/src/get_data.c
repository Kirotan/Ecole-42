/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:39 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/24 17:33:08 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_meal_eaten = data->nb_time_must_eat;
		philo[i].time_before_die = data->time_to_die;
		philo[i].data = data;
		philo[i].own_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].own_fork)
		{
			freeing_machine_loop(philo, i);
			check_if(ERROR_MALLOC);
		}
		pthread_mutex_init(philo[i].own_fork, NULL);
		if (i > 0)
			philo[i].left_fork = philo[i - 1].own_fork;
		i++;
	}
	philo[0].left_fork = philo[data->nb_philo - 1].own_fork;
}

static void	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1000;
	data->time_to_eat = ft_atol(argv[3]) * 1000;
	data->time_to_sleep = ft_atol(argv[4]) * 1000;
	data->is_it_dead = malloc(sizeof(pthread_mutex_t));
	if (!data[0].is_it_dead)
		check_if(ERROR_MALLOC);
	if (argc == 6)
		data->nb_time_must_eat = ft_atol(argv[5]);
	else
		data->nb_time_must_eat = INT_MAX;
}

int	get_data(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	init_data(argc, argv, &data);
	philo = malloc(sizeof(t_philo) * data.nb_philo);
	if (!philo)
		return (check_if(ERROR_MALLOC));
	init_philo(&data, philo);
	if (mechanism(philo) == 1)
	{
		freeing_machine(philo);
		check_if(ERROR_THREAD);
	}
	freeing_machine(philo);
	return (0);
}
