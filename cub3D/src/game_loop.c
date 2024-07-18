#include "../include/cub3D.h"

void	game_loop(void *the_mlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)the_mlx;
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H);
	display_background(mlx);
	display_map(mlx);
	display_gamer(mlx);
	gamer_movement(mlx);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}
