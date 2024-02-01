/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   drawing.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: gdoumer <gdoumer@student.42.fr>	+#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/01/29 11:41:34 by gdoumer	   #+#	#+#	 */
/*   Updated: 2024/01/31 21:08:26 by gdoumer	  ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx_ptr, x, y, color);
}

void	drawing_map(t_stray *array, mlx_image_t *img)
{
	int		i;

	i = 0;
	while (array[0].len_total - 1 > i)
	{
		if ((i + 1) % array[0].len_line != 0)
			draw(array[i], array[i + 1], img);
		if (array[0].len_total - array[0].len_line > i)
			draw(array[i], array[i + array[0].len_line], img);
		i++;
	}
}

// static void	drawing_raw(t_stray start, t_stray end,
// 	mlx_img_t *img)
// {
// 	int	x;
// 	int	y;
// 	int	delta_x;
// 	int	delta_y;
// 	int	param_k;

// 	x = start.x + start.start_x;
// 	y = start.y + start.start_y;
// 	delta_x = (end.x - start.x);
// 	delta_y = (end.y - start.y);
// 	param_k = 2 * delta_x - delta_y;
// 	while (y <= (end.y + start.start_y))
// 	{
// 		if (param_k >= 0)
// 		{
// 			param_k = param_k + (2 * delta_x) - (2 * delta_y);
// 			x = x + 1;
// 		}
// 		else
// 			param_k = param_k + (2 * delta_x);
// 		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
// 			mlx_put_pixel(img, x, y, 0x00AAAAFF);
// 		y = y + 1;
// 	}
// }

// static void	drawing_line(t_stray start, t_stray end,
// 	mlx_img_t *img)
// {
// 	int	x;
// 	int	y;
// 	int	delta_x;
// 	int	delta_y;
// 	int	param_k;

// 	x = start.x + start.start_x;
// 	y = start.y + start.start_y;
// 	delta_x = (end.x - start.x);
// 	delta_y = (end.y - start.y);
// 	param_k = 2 * delta_y - delta_x;
// 	while (x <= (end.x + start.start_x))
// 	{
// 		if (param_k >= 0)
// 		{
// 			param_k = param_k + (2 * delta_y) - (2 * delta_x);
// 			y = y + 1;
// 		}
// 		else
// 			param_k = param_k + (2 * delta_y);
// 		if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
// 			mlx_put_pixel(img, x, y, 0xFF0000FF);
// 		x = x + 1;
// 	}
// }

// void	drawing_map(t_stray *array, mlx_img_t *img)
// {
// 	int		i;

// 	i = 0;
// 	calcul_center(array);
// 	while (array[0].len_total - 1 > i)
// 	{
// 		drawing_line(array[i], array[i + 1], img);
// 		if (array[0].len_total - array[0].len_line > i)
// 			drawing_raw(array[i], array[i + array[0].len_line], img);
// 		i++;
// 	}
// }
