/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:39 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/21 14:11:18 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(int argc, char **argv, t_data data, t_philo **philo)
{

}

static void	init_data(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->nb_time_must_eat = ft_atol(argv[5]);
	else
		data->nb_time_must_eat = -1;
}

int	get_data(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	init_data(argc, argv, &data);
	init_philo(argc, argv, data, &philo);
	return (0);
}
