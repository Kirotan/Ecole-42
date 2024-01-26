/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:55:30 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 15:44:14 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
}	t_stray;

typedef struct s_coordinates
{
	int		x;
	int		y;
	size_t	j;
}	t_coordinates;

t_stray	*extract_map(char *name_map);
void	check_argc(int argc);
t_stray	*fill_array(char *final_line, size_t len);

#endif
