/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:44 by gdoumer           #+#    #+#             */
/*   Updated: 2024/03/04 13:46:54 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_display(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->data->write_dead);
	if (ft_strncmp(message, "died", 4) == 0)
		philo->data->already_write_dead++;
	if (philo->data->already_write_dead == 0)
		printf(MESSAGE, get_time()
			- philo->data->start_time, philo->id, message);
	else if (ft_strncmp(message, "died", 4) == 0
		&& philo->data->already_write_dead == 1)
	{
		printf(MESSAGE, get_time()
			- philo->data->start_time, philo->id, message);
	}
	pthread_mutex_unlock(philo->data->write_dead);
}

long int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (check_if(ERROR_TIME));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;
	long	nbr;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	only_one(t_philo *philo)
{
	philo[0].data->start_time = get_time();
	ft_display(philo, FORK);
	usleep(philo->data->time_to_die);
	ft_display(philo, DIE);
	freeing_machine(philo);
}
