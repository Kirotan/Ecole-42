/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/02 21:11:56 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	(void)mlx;
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_stray		*array;

	array = NULL;
	check_argc(argc);
	extract_map(argv[1], &array);
	rotation_x(array, 45);
	rotation_y(array,20);
	rotation_z(array, 0);
	re_calcul_center(array);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (EXIT_FAILURE);
	drawing_map(array, img);
	free(array);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
