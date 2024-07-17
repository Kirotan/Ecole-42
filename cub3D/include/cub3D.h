#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

# define ERR "Error\n"
# define BAD_ARG "Bad argument\n"
# define FILE_ERR "Bad map file extension\n"
# define FD_ERR "File descriptor error\n"
# define EMPT_MAP "Empty map\n"
# define COLOR_ERR "Color error\n"
# define S_W 1920 // screen width
# define S_H 1080 // screen height
# define TILE_SIZE 64
# define FOV 66 // field of view
# define ROTATION_SPEED 3
# define GAMER_SPEED 70
# define GAMER_SIZE 32
# define ERR "Error\n"
# define BAD_ARG "Bad argument\n"
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define GREY 0x808080FF
# define ORANGE 0xFFA500FF
# define BROWN 0xA52A2AFF
# define PINK 0xFFC0CBFF
# define PURPLE 0x800080FF


typedef struct s_gamer
{
	double		gmr_x;
	double		gmr_y;
	double		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}		t_gamer;

typedef struct s_ray
{
	int		index;
	double	ray_angle;
	double	distance;
	int		flag;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
}		t_ray;

typedef struct s_texture
{
	mlx_texture_t	*path_no;
	mlx_texture_t	*path_so;
	mlx_texture_t	*path_we;
	mlx_texture_t	*path_ea;
}		t_texture;

typedef struct s_data
{
	char		**map2d;
	int			p_x; //coordonnees X du joueur
	int			p_y; //coordonnees Y du joueur
	int			w_map; //largeur de la map
	int			h_map; //hauteur de la map
	t_texture	tex;
	int32_t		color_f;
	int32_t		color_c;
}		t_data;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_data		*dt;
	t_gamer		*gmr;
}		t_mlx;

void	power_on(t_data *dt);
void	init_gamer(t_mlx *mlx);
void	game_loop(void *the_mlx);
void	movement(mlx_key_data_t mov, void *param);
void	display_background(t_mlx *mlx);
void	draw_wall_square(t_mlx *mlx, int x, int y, int color);
void	display_gamer(t_mlx *mlx);
void	draw_circle(t_mlx *mlx, int x0, int y0, int size);
void	display_map(t_mlx *mlx);
void	normalize_angle(t_mlx *mlx);
void	gamer_movement(t_mlx *mlx);
void	ft_free_all(t_mlx *mlx);

#endif
