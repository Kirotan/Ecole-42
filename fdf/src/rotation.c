/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:49:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 19:52:25 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_stray *array, int angle)
{
	int		i;
	double	radian;
	double	y;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			y = array[i].y;
			array[i].y = y * cos(radian) - array[i].z * sin(radian);
			array[i].z = y * sin(radian) + array[i].z * cos(radian);
			i++;
		}
	}
}

void	rotation_y(t_stray *array, int angle)
{
	int		i;
	double	radian;
	double	x;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			array[i].x = x * cos(radian) + array[i].z * sin(radian);
			array[i].z = -x * sin(radian) + array[i].z * cos(radian);
			i++;
		}
	}
}

void	rotation_z(t_stray *array, int angle)
{
	int		i;
	double	radian;
	double	x;

	if (angle != 0)
	{
		i = 0;
		radian = angle * (M_PI / 180);
		while (i < array->len_total)
		{
			x = array[i].x;
			array[i].x = x * cos(radian) - array[i].y * sin(radian);
			array[i].y = x * sin(radian) + array[i].y * cos(radian);
			i++;
		}
	}
}
