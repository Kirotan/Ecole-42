/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:49:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 18:59:10 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_stray *array, int angle)
{
	int		i;
	int		j;
	float	radian;
	double	y;
	double	z;

	i = 0;
	j = 0;
	radian = angle * (M_PI / 180);
	while (array[i].z)
	{
		y = array[i].y;
		z = array[i].z;
		array[i].y = y * cos(radian) + z * sin(radian);
		array[i].z = -y * sin(radian) + z * cos(radian);
		i++;
	}
}

void	rotation_y(t_stray *array, int angle)
{
	int		i;
	int		j;
	float	radian;
	double	x;
	double	z;

	i = 0;
	j = 0;
	radian = angle * (M_PI / 180);
	while (array[i].z)
	{
		x = array[i].x;
		z = array[i].z;
		array[i].x = x * cos(radian) + z * sin(radian);
		array[i].z = -x * sin(radian) + z * cos(radian);
		i++;
	}
}

void	rotation_z(t_stray *array, int angle)
{
	int		i;
	int		j;
	float	radian;
	double	x;
	double	y;

	i = 0;
	j = 0;
	radian = angle * (M_PI / 180);
	while (array[i].z)
	{
		x = array[i].x;
		y = array[i].y;
		array[i].x = x * cos(radian) - y * sin(radian);
		array[i].y = x * sin(radian) + y * cos(radian);
		i++;
	}
}
