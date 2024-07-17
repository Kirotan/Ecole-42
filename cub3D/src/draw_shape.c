#include "../include/cub3D.h"

void	draw_circle(t_mlx *mlx, int x0, int y0, int size)
{
	int		x;
	int		y;
	int		i;
	int		radius;

	radius = size / 2;
	i = 0;
	while (i < 360)
	{
		x = (int)(x0 + radius * cos(mlx->gmr->fov_rd));
		y = (int)(y0 + radius * sin(mlx->gmr->fov_rd));
		mlx_put_pixel(mlx->img, x, y, GREEN);
		i++;
	}
}

void	draw_wall_square(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_put_pixel(mlx->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
