/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:42:40 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/01 13:52:13 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calcul_center(t_stray *array)
{
	int	map_height;
	int	map_width;
	int	start_x;
	int	start_y;
	int	i;

	map_height = (array[0].len_total / array[0].len_line);
	map_width = array[0].len_line;
	start_x = (WIDTH - map_width) / 2;
	start_y = (HEIGHT - map_height) / 2;
	i = 0;
	while (array[0].len_total > i)
	{
		array[i].start_x = start_x;
		array[i].start_y = start_y;
		i++;
	}
}
