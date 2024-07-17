#include "../include/cub3D.h"

void	ft_free_all(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->dt->map2d[i])
		free(mlx->dt->map2d[i++]);
	free(mlx->dt->map2d);
	free(mlx->gmr);
	free(mlx->ray);
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx_close_window(mlx->mlx_p);
	mlx_terminate(mlx->mlx_p);
	printf("pikapika\n");
	exit(0);
}
