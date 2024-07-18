#include "../include/cub3D.h"

void	cast_rays(t_mlx *mlx)
{
	double	inter_h;
	double	inter_v;
	int		i;

	i = 0;
	while (i < S_W)
	{
		inter_v = inter_verti(mlx);
		inter_h = inter_horiz(mlx);
		if (inter_v < inter_h)
			mlx->ray->distance = inter_v;
		else
			mlx->ray->distance = inter_h;
		i++;
		mlx->ray->ray_angle += mlx->gmr->fov_rd / S_W;
	}
}
