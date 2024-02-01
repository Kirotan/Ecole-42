/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:55:30 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/01 13:51:08 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 3000
# define HEIGHT 1500

# include "MLX42.h"
# include "../src/libft/include/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_struc_array
{
	int			a;
	double		x;
	double		y;
	double		z;
	int			r;
	int			g;
	int			b;
	int			len_total;
	int			len_line;
	int			start_x;
	int			start_y;
}	t_stray;

typedef struct s_coordinates
{
	int		x;
	int		y;
	size_t	j;
	size_t	start;
	size_t	i;
}	t_coordinates;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		inc_y;
	int		inc_x;
	int		hill;
	int		error;
	int		inc_e;
	int		p;
}	t_bres;

t_stray	*extract_map(char *name_map);
void	check_argc(int argc);
t_stray	*fill_array(char *final_line, size_t len);
void	r_g_b(char *temp, t_stray *array, t_coordinates coord);
void	drawing_map(t_stray *array, mlx_image_t	*img);
void	draw(t_stray start, t_stray end, void *img);
void	draw_pixel(void *mlx_ptr, int32_t x, int32_t y, int32_t color);
void	rotation_x(t_stray *array, int angle);
void	rotation_y(t_stray *array, int angle);
void	rotation_z(t_stray *array, int angle);
void	calcul_center(t_stray *array);

#endif
