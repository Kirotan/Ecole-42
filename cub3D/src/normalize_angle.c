#include "../include/cub3D.h"

void	normalize_angle(t_mlx *mlx)
{
	if (mlx->gmr->angle < 0)
		mlx->gmr->angle += 2 * M_PI;
	else if (mlx->gmr->angle > 2 * M_PI)
		mlx->gmr->angle -= 2 * M_PI;
}
