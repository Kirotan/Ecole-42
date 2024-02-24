/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:15:31 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/24 14:26:51 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (check_error(argc, argv) == 1)
		return (1);
	if (get_data(argc, argv) == 1)
		return (1);
	return (0);
}
