/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:39 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/27 17:15:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_meal_eaten = data->nb_time_must_eat;
		philo[i].data = data;
		philo[i].time_since_last_meal = 0;
		philo[i].last_meal = 0;
		philo[i].own_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].own_fork)
		{
			freeing_machine_loop(philo, i);
			check_if(ERROR_MALLOC);
			return (1);
		}
		pthread_mutex_init(philo[i].own_fork, NULL);
		if (i > 0)
			philo[i].left_fork = philo[i - 1].own_fork;
		i++;
	}
	philo[0].left_fork = philo[data->nb_philo - 1].own_fork;
	return (0);
}

static int	init_data_2(t_data *data)
{
	data->is_it_dead = malloc(sizeof(pthread_mutex_t));
	if (!data->is_it_dead)
	{
		check_if(ERROR_MALLOC);
		return (1);
	}
	pthread_mutex_init(data->is_it_dead, NULL);
	data->write_dead = malloc(sizeof(pthread_mutex_t));
	if (!data->write_dead)
	{
		check_if(ERROR_MALLOC);
		free(data->is_it_dead);
		return (1);
	}
	pthread_mutex_init(data->write_dead, NULL);
	return (0);
}

static int	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atol(argv[1]);
	if (data->nb_philo == 0)
		return (1);
	data->time_to_die = ft_atol(argv[2]) * 1000;
	data->time_to_eat = ft_atol(argv[3]) * 1000;
	data->time_to_sleep = ft_atol(argv[4]) * 1000;
	data->dead = 0;
	data->already_write_dead = 0;
	init_data_2(data);
	if (argc == 6)
		data->nb_time_must_eat = ft_atol(argv[5]);
	else
		data->nb_time_must_eat = INT_MAX;
	return (0);
}

int	get_data(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (init_data(argc, argv, &data) == 1)
		return (1);
	philo = malloc(sizeof(t_philo) * data.nb_philo);
	if (!philo)
		return (check_if(ERROR_MALLOC));
	if (init_philo(&data, philo) == 1)
		return (1);
	if (mechanism(philo) == 1)
	{
		check_if(ERROR_THREAD);
		freeing_machine(philo);
		return (1);
	}
	else
	{
		freeing_machine(philo);
		return (0);
	}
	return (0);
}
