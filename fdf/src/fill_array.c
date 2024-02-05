/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 19:19:32 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	put_line_in_tab(char *str, t_stray *array, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(str, ' ');
	if (!points)
		verif_1(str, array, &i, j);
	while (points[i] != NULL)
	{
		if (ft_isdigit(points[i][0]) == 0)
		{
			free(points);
			verif_2(str, array, &i, j);
		}
		if (*j < array[0].len_total)
		{
			array[*j].z = ft_atoi(points[i]) * array[0].height_of_z;
			array[*j].x = i;
			array[*j].y = (*j / array[0].len_line);
			array[*j].color = ft_strlower(get_color(points[i]));
			if (array[*j].color == NULL)
			{
				if (array[*j].z > 0)
				{
					array[*j].color = ft_strdup("ff00ffff");
					verif_4(array, points, points[i], j);
					verif_3(str, array, &i, j);
				}
				else
				{
					array[*j].color = ft_strdup("ff3070ff");
					verif_4(array, points, points[i], j);
					verif_3(str, array, &i, j);
				}
			}
			(*j)++;
		}
		free(points[i]);
		i++;
	}
	free(points[i]);
	free(points);
	verif_5(array, j, i);
	return (0);
}

int	extract_map(char *fdname, t_stray **array)
{
	int			fd;
	char		*str;
	int			j;

	fd = check_fd(fdname);
	str = get_next_line(fd);
	check_gnl(str);
	*array = ft_calloc(((get_nb_row(str, ' '))
				* get_nb_lines(fdname)), sizeof(t_stray));
	if (!*array)
	{
		free(str);
		close(fd);
		exit (EXIT_FAILURE);
	}
	give_value(*array, str, fdname);
	j = 0;
	while (str != NULL)
	{
		put_line_in_tab(str, *array, &j);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
