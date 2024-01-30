/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:49:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/30 11:17:46 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_stray *array, int angle)
{
	int		i;
	double	y;

	if (angle != 0)
	{
		i = 0;
		angle = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			y = array[i].y;
			array[i].y = y * cos(angle) - array[i].z * sin(angle);
			array[i].z = y * sin(angle) + array[i].z * cos(angle);
			i++;
		}
	}
}

void	rotation_y(t_stray *array, int angle)
{
	int		i;
	double	x;

	if (angle != 0)
	{
		i = 0;
		angle = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			array[i].x = x * cos(angle) + array[i].z * sin(angle);
			array[i].z = -x * sin(angle) + array[i].z * cos(angle);
			i++;
		}
	}
}

void	rotation_z(t_stray *array, int angle)
{
	int		i;
	double	x;

	if (angle != 0)
	{
		i = 0;
		angle = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			array[i].x = x * cos(angle) - array[i].y * sin(angle);
			array[i].y = x * sin(angle) + array[i].y * cos(angle);
			i++;
		}
	}
}
