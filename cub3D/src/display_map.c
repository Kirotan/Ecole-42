#include "../include/cub3D.h"

void	display_map(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx->dt->h_map)
	{
		y = 0;
		while (y < mlx->dt->w_map)
		{
			if (mlx->dt->map2d[x][y] == '1')
				draw_wall_square(mlx, y * TILE_SIZE, x * TILE_SIZE, BLACK);
			else if (mlx->dt->map2d[x][y] == '0')
				draw_wall_square(mlx, y * TILE_SIZE, x * TILE_SIZE, WHITE);
			y++;
		}
		x++;
	}
}
