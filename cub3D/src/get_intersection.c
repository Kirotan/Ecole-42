#include "../include/cub3D.h"

double	wall_or_not(t_mlx *mlx, double coord_x, double coord_y)
{
	int	x_on_map;
	int	y_on_map;

	if (coord_x < 0 || coord_y < 0)
		return (0);
	x_on_map = floor(coord_x / TILE_SIZE);
	y_on_map = floor(coord_y / TILE_SIZE);
	if (y_on_map >= mlx->dt->h_map || x_on_map >= mlx->dt->w_map)
		return (0);
	if (mlx->dt->map2d[y_on_map][x_on_map] == '1')
		return (0);
	return (1);
}

static void	horiz_check_up_or_down(t_mlx *mlx, double *dist_y, double *coord_y)
{
	if (mlx->gmr->angle > 0 && mlx->gmr->angle < M_PI)
	{
		*dist_y = -TILE_SIZE;
		*coord_y = floor(mlx->gmr->gmr_y / TILE_SIZE) * TILE_SIZE - 1;
	}
	else
	{
		*dist_y = TILE_SIZE;
		*coord_y = floor(mlx->gmr->gmr_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
}

double	inter_horiz(t_mlx *mlx)
{
	double	coord_y;
	double	coord_x;
	double	dist_x;
	double	dist_y;

	dist_y = 0;
	coord_y = 0;
	horiz_check_up_or_down(mlx, &dist_y, &coord_y);
	coord_x = mlx->gmr->gmr_x + (mlx->gmr->gmr_y - coord_y)
		/ tan(mlx->ray->ray_angle);
	dist_x = TILE_SIZE / tan(mlx->ray->ray_angle);
	while (wall_or_not(mlx, coord_x, coord_y))
	{
		coord_x += dist_x;
		coord_y += dist_y;
	}
	mlx->ray->horiz_x = coord_x;
	mlx->ray->horiz_y = coord_y;
	return (sqrt(pow(coord_x - mlx->gmr->gmr_x, 2)
			+ pow(coord_y - mlx->gmr->gmr_y, 2)));
}

static void	verti_check_l_or_r(t_mlx *mlx, double *dist_x, double *coord_x)
{
	if (mlx->gmr->angle > 0 && mlx->gmr->angle < M_PI)
	{
		*dist_x = TILE_SIZE;
		*coord_x = floor(mlx->gmr->gmr_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	}
	else
	{
		*dist_x = -TILE_SIZE;
		*coord_x = floor(mlx->gmr->gmr_x / TILE_SIZE) * TILE_SIZE - 1;
	}
}

double	inter_verti(t_mlx *mlx)
{
	double	coord_y;
	double	coord_x;
	double	dist_x;
	double	dist_y;

	dist_x = 0;
	coord_x = 0;
	verti_check_l_or_r(mlx, &dist_x, &coord_x);
	coord_y = mlx->gmr->gmr_y + (mlx->gmr->gmr_x - coord_x)
		* tan(mlx->ray->ray_angle);
	dist_y = TILE_SIZE * tan(mlx->ray->ray_angle);
	while (wall_or_not(mlx, coord_x, coord_y))
	{
		coord_x += dist_x;
		coord_y += dist_y;
	}
	mlx->ray->horiz_x = coord_x;
	mlx->ray->horiz_y = coord_y;
	return (sqrt(pow(coord_x - mlx->gmr->gmr_x, 2)
			+ pow(coord_y - mlx->gmr->gmr_y, 2)));
}
