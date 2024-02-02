/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/02 22:11:45 by gdoumer          ###   ########.fr       */
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

static char	*get_color(char *str)
{
	int		j;
	char	*r;
	int		i;

	i = 0;
	printf("%s\n", str);
	while (str[i] != '\0')
	{
		if (str[i] == 'x')
			break ;
		else if (str[i + 1] == '\0')
			return (NULL);
		i++;
	}
	j = 0;
	while (*str != 'x' && *str != '\0')
		str++;
	str++;
	r = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 3);
	if (!r)
		return (NULL);
	while (*str != '\0')
	{
		r[j] = *str;
		j++;
		str++;
	}
	r[j] = 'f';
	r[j + 1] = 'f';
	printf("r: %s\n", r);
	return (r);
}

char	*ft_strlower(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static int	put_line_in_tab(char *a_line, t_stray *array, int *j, int ratio)
{
	char	**points;
	int		i;

	i = 0;
	points = ft_split(a_line, ' ');
	while (points[i] != NULL)
	{
		array[*j].z = ft_atoi(points[i]) * 3;
		array[*j].x = (i * ratio);
		array[*j].y = (*j / array[0].len_line) * ratio;
		array[*j].color = ft_strlower(get_color(points[i]));
		if (array[*j].color == NULL)
			array[*j].color = ft_strdup("ffffffff");
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
	int			ratio;

	ratio = 50;
	fd = open(fdname, O_RDONLY);
	if (!fd)
		return (1);
	str = get_next_line(fd);
	*array = calloc(((get_nb_strs(str, ' '))
				* get_nb_lines(fdname)), sizeof(t_stray));
	array[0]->ratio = ratio;
	i = 0;
	(*array[0]).len_line = get_nb_strs(str, ' ');
	(*array[0]).len_raw = get_nb_lines(fdname);
	(*array)[0].len_total = (*array)[0].len_line * (*array)[0].len_raw;
	while (str != NULL)
	{
		put_line_in_tab(str, *array, &i, ratio);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
