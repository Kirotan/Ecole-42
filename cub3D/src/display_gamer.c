#include "../include/cub3D.h"

void	display_gamer(t_mlx *mlx)
{
	double		x;
	double		y;
	int			i;
	double		radius;
	double		rad;

	radius = GAMER_SIZE / 2;
	i = 0;
	while (i < 360)
	{
		rad = (i * M_PI) /180 ;
		x = (double)(mlx->gmr->gmr_x + radius * cos(rad));
		y = (double)(mlx->gmr->gmr_y + radius * sin(rad));
		mlx_put_pixel(mlx->img, x, y, PURPLE);
		i++;
	}
}
