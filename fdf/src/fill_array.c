/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/03 21:29:07 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static int	put_line_in_tab(char *a_line, t_stray *array, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	while (points[i] != NULL)
	{
		array[*j].z = ft_atoi(points[i]) * array[0].height_of_z;
		array[*j].x = (i * array[0].ratio);
		array[*j].y = (*j / array[0].len_line) * array[0].ratio;
		array[*j].color = ft_strlower(get_color(points[i]));
		if (array[*j].color == NULL)
		{
			if (array[*j].z > 0)
				array[*j].color = ft_strdup("ff00ffff");
			else
				array[*j].color = ft_strdup("ff3070ff");
		}
		free(points[i]);
		i++;
		(*j)++;
	}
	free(points[i]);
	free(points);
	return (0);
}

static int	get_nb_lines(char *fdname)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(fdname, O_RDONLY);
	if (!fd)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	extract_map(char *fdname, t_stray **array)
{
	int			fd;
	char		*str;
	int			i;

	fd = open(fdname, O_RDONLY);
	if (!fd)
		return (1);
	str = get_next_line(fd);
	*array = calloc(((get_nb_strs(str, ' '))
				* get_nb_lines(fdname)), sizeof(t_stray));
	i = 0;
	array[0]->ratio = 10;
	array[0]->height_of_z = 3;
	(*array[0]).len_line = get_nb_strs(str, ' ');
	(*array[0]).len_raw = get_nb_lines(fdname);
	(*array)[0].len_total = (*array)[0].len_line * (*array)[0].len_raw;
	while (str != NULL)
	{
		put_line_in_tab(str, *array, &i);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
