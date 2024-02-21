/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:16:22 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/21 16:26:45 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define ERROR_MALLOC "Error : malloc failed.\n"
# define ERROR_THREAD "Error : thread failed.\n"

typedef struct s_data
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_time_must_eat;
	int		start_time;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				nb_meal_eaten;
	int				time_before_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*own_fork;
	t_data			*data;
}				t_philo;

int		check_error(int argc, char **argv);
long	ft_atol(const char *nptr);
int		get_data(int argc, char **argv);
int		check_if(char *message);
void	mechanism(t_philo *philo);

#endif
