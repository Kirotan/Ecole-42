#include "../include/cub3D.h"

void	display_gamer(t_mlx *mlx)
{
	int		x;
	int		y;
	int		i;
	int		radius;

	radius = GAMER_SIZE;
	i = 0;
	while (i < 360)
	{
		x = (int)(mlx->gmr->gmr_x + radius * cos(mlx->gmr->fov_rd));
		y = (int)(mlx->gmr->gmr_y + radius * sin(mlx->gmr->fov_rd));
		mlx_put_pixel(mlx->img, x, y, PURPLE);
		i++;
	}
}
