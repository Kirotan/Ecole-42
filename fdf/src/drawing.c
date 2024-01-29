/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:34 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 18:35:09 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawing_raw(t_stray start, t_stray end,
	mlx_image_t *img, int ratio)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	param_k;

	x = start.x * ratio;
	y = start.y * ratio;
	delta_x = end.x * ratio - start.x * ratio;
	delta_y = end.y * ratio - start.y * ratio;
	param_k = 2 * delta_x - delta_y;
	while (y <= end.y * ratio)
	{
		if (param_k >= 0)
		{
			param_k = param_k + 2 * delta_x - 2 * delta_y;
			x = x + 1;
		}
		else
			param_k = param_k + 2 * delta_x;
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		y = y + 1;
	}
}

static void	drawing_line(t_stray start, t_stray end,
	mlx_image_t *img, int ratio)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	param_k;

	x = start.x * ratio;
	y = start.y * ratio;
	delta_x = end.x * ratio - start.x * ratio;
	delta_y = end.y * ratio - start.y * ratio;
	param_k = 2 * delta_y - delta_x;
	while (x <= end.x * ratio)
	{
		if (param_k >= 0)
		{
			param_k = param_k + 2 * delta_y - 2 * delta_x;
			y = y + 1;
		}
		else
			param_k = param_k + 2 * delta_y;
		mlx_put_pixel(img, x, y, 0xFFFFFFFF);
		x = x + 1;
	}
}

void	drawing_map(t_stray *array, mlx_image_t *img, int ratio)
{
	int	i;

	ratio = ratio;
	i = 0;
	while (array[0].len_total - 1 > i)
	{
		drawing_line(array[i], array[i + 1], img, ratio);
		if (array[0].len_total - array[0].len_line > i)
			drawing_raw(array[i], array[i + array[0].len_line], img, ratio);
		i++;
	}
}
