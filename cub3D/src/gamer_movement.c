#include "../include/cub3D.h"

static void	update_move(t_mlx *mlx, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->gmr->gmr_x + move_x);
	new_y = roundf(mlx->gmr->gmr_y + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (mlx->dt->map2d[map_y][map_x] != '1'
		&& (mlx->dt->map2d[map_y][(int)mlx->gmr->gmr_x / TILE_SIZE] != '1'
		&& mlx->dt->map2d[(int)mlx->gmr->gmr_y / TILE_SIZE][map_x] != '1'))
	{
		mlx->gmr->gmr_x = new_x;
		mlx->gmr->gmr_y = new_y;
	}
}

static void	rotate_gamer(t_mlx *mlx)
{
	if (mlx->gmr->rot == 1)
	{
		mlx->gmr->angle += ROTATION_SPEED * mlx->mlx_p->delta_time;
		if (mlx->gmr->angle > 2 * M_PI)
			mlx->gmr->angle -= 2 * M_PI;
	}
	else if (mlx->gmr->rot == -1)
	{
		mlx->gmr->angle -= ROTATION_SPEED * mlx->mlx_p->delta_time;
		if (mlx->gmr->angle < 0)
			mlx->gmr->angle += 2 * M_PI;
	}
}

void	up_down_move(t_mlx *mlx)
{
	if (mlx->gmr->u_d == 1)
	{
		mlx->gmr->gmr_x += cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		mlx->gmr->gmr_y += sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	else if (mlx->gmr->u_d == -1)
	{
		mlx->gmr->gmr_x += -cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		mlx->gmr->gmr_y += -sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
}

void	left_right_move(t_mlx *mlx)
{
	if (mlx->gmr->l_r == -1)
	{
		mlx->gmr->gmr_x += sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		mlx->gmr->gmr_y += -cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	else if (mlx->gmr->l_r == 1)
	{
		mlx->gmr->gmr_x += -sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		mlx->gmr->gmr_y += cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
}

void	gamer_movement(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	rotate_gamer(mlx);
	up_down_move(mlx);
	left_right_move(mlx);
	update_move(mlx, move_x, move_y);
}
