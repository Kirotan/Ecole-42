/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:41:34 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/31 16:20:22 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calcul_center(t_stray *array, int ratio)
{
	int	map_height;
	int	map_width;
	int	start_x;
	int	start_y;
	int	i;

	map_height = (array[0].len_total / array[0].len_line) * ratio;
	map_width = array[0].len_line * ratio;
	start_x = (WIDTH - map_width) / 2;
	start_y = (HEIGHT - map_height) / 2;
	i = 0;
	while (array[0].len_total > i)
	{
		array[i].start_x = start_x;
		array[i].start_y = start_y;
		i++;
	}
}

static void	drawing_raw(t_stray start, t_stray end,
	mlx_image_t *img, int ratio)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	param_k;

	x = (start.x * ratio) + start.start_x;
	y = (start.y * ratio) + start.start_y;
	delta_x = (end.x - start.x) * ratio;
	delta_y = (end.y - start.y) * ratio;
	param_k = 2 * delta_x - delta_y;
	while (y <= end.y * ratio + start.start_y)
	{
		if (param_k >= 0)
		{
			param_k = param_k + (2 * delta_x) - (2 * delta_y);
			x = x + 1;
		}
		else
			param_k = param_k + 2 * delta_x;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx_put_pixel(img, x, y, 0x00AAAAFF);
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

	x = (start.x * ratio) + start.start_x;
	y = (start.y * ratio) + start.start_y;
	delta_x = (end.x - start.x) * ratio;
	delta_y = (end.y - start.y) * ratio;
	param_k = 2 * delta_y - delta_x;
	while (x <= (end.x * ratio + start.start_x))
	{
		if (param_k >= 0)
		{
			param_k = param_k + (2 * delta_y) - (2 * delta_x);
			y = y + 1;
		}
		else
			param_k = param_k + 2 * delta_y;
		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
			mlx_put_pixel(img, x, y, 0xFF0000FF);
		x = x + 1;
	}
}

void	drawing_map(t_stray *array, mlx_image_t *img)
{
	int	i;
	int	ratio;

	i = 0;
	ratio = 30;
	calcul_center(array, ratio);
	while (array[0].len_total - 1 > i)
	{
		drawing_line(array[i], array[i + 1], img, ratio);
		if (array[0].len_total - array[0].len_line > i)
			drawing_raw(array[i], array[i + array[0].len_line], img, ratio);
		i++;
	}
}
