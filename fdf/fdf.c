/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/22 18:45:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WIDTH 1920
#define HEIGHT 1080

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			**map_array;

	map_array = extract_array(argv[0])
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
