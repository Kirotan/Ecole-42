/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:55:30 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/29 16:08:01 by gdoumer          ###   ########.fr       */
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
	int		a;
	int		x;
	int		y;
	int		z;
	int		r;
	int		g;
	int		b;
	int		len_total;
	int		len_line;
}	t_stray;

typedef struct s_coordinates
{
	int		x;
	int		y;
	size_t	j;
	size_t	start;
	size_t	i;
}	t_coordinates;

t_stray	*extract_map(char *name_map);
void	check_argc(int argc);
t_stray	*fill_array(char *final_line, size_t len);
void	r_g_b(char *temp, t_stray *array, t_coordinates coord);
void	drawing_map(t_stray *array, mlx_image_t	*img, int ratio);

#endif
