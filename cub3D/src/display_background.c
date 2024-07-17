#include "../include/cub3D.h"

void	display_background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < S_W)
	{
		y = 0;
		while (y < S_H)
		{
			mlx_put_pixel(mlx->img, x, y, GREY);
			y++;
		}
		x++;
	}
}
