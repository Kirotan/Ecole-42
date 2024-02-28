/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:16:22 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/28 12:17:39 by gdoumer          ###   ########.fr       */
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
# define ERROR_TIME "Error : gettimeofday failed.\n"
# define FORK "has taken"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define MESSAGE "%ld %d %s\n"

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_time_must_eat;
	time_t				start_time;
	pthread_mutex_t		*is_it_dead;
	pthread_mutex_t		*write_dead;
	int					dead;
	int					already_write_dead;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				nb_meal_eaten;
	time_t			time_since_last_meal;
	time_t			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*own_fork;
	t_data			*data;
}				t_philo;

int			check_error(int argc, char **argv);
long		ft_atol(const char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_data(int argc, char **argv);
int			check_if(char *message);
int			mechanism(t_philo *philo);
void		ft_display(t_philo *philo, char *message);
long int	get_time(void);
int			take_fork(t_philo *philo);
int			give_way_fork(t_philo *philo);
int			ft_dionysos(t_philo *philo);
int			ft_athena(t_philo *philo);
int			ft_morphe(t_philo *philo);
int			freeing_machine(t_philo *philo);
int			freeing_machine_loop(t_philo *philo, int i);
int			ft_thanatos_master(t_philo *philo);
int			ft_thanatos_eater(t_philo *philo);
void		only_one(t_philo *philo);

#endif
