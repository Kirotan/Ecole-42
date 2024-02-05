/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 18:01:59 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	get_nb_row(char const *s, char c)
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

static int	put_line_in_tab(char *str, t_stray *array, int *j)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(str, ' ');
	if (!points)
	{
		free(str);
		while (i < *j)
		{
			free(array[i].color);
			i++;
		}
		free(array);
		perror("Malloc error.\n");
		exit (EXIT_FAILURE);
	}
	while (points[i] != NULL)
	{
		if (ft_isdigit(points[i][0]) == 0)
		{
			free(points);
			free(str);
			while (i < *j)
			{
				free(array[i].color);
				i++;
			}
			free(array);
			perror("Bad digit.\n");
			exit (EXIT_FAILURE);
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
					if (!array[*j].color)
					{
						free(str);
						free(points[i]);
						free(points);
						while (i < *j)
						{
							free(array[i].color);
							i++;
						}
						free(array);
						perror("Malloc error, transparent line.\n");
						exit (EXIT_FAILURE);
					}
				}
				else
				{
					array[*j].color = ft_strdup("ff3070ff");
					if (!array[*j].color)
					{
						free(str);
						free(points[i]);
						free(points);
						while (i < *j)
						{
							free(array[i].color);
							i++;
						}
						free(array);
						perror("Malloc error, transparent line.\n");
						exit (EXIT_FAILURE);
					}
				}
			}
			(*j)++;
		}
		free(points[i]);
		i++;
	}
	free(points[i]);
	free(points);
	if (i != array[0].len_line)
	{
		i = 0;
		while (i < *j)
		{
			free(array[i].color);
			i++;
		}
		free(array);
		perror("Bad line.\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}

static int	get_nb_lines(char *fdname)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = check_fd(fdname);
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

static void	give_value(t_stray *array, char *str, char *fdname)
{
	array[0].height_of_z = 5;
	array[0].len_line = get_nb_row(str, ' ');
	array[0].len_raw = get_nb_lines(fdname);
	array[0].len_total = array[0].len_line * array[0].len_raw;
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
