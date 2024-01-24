/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/24 15:01:47 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*del_return_line(char *final_line)
{
	size_t	i;

	i = 0;
	while (final_line[i])
	{
		if (final_line[i] == '\n')
			final_line[i] = 32;
		i++;
	}
	return (final_line);
}

static char	*join_line(int fd)
{
	char	*s1;
	char	*s2;

	s1 = get_next_line(fd);
	if (!s1)
	{
		perror("Empty map.");
		exit (EXIT_SUCCESS);
	}
	s2 = get_next_line(fd);
	if (!s2)
		return (s1);
	while (s2)
	{
		s1 = ft_strjoin(s1, s2);
		free(s2);
		s2 = get_next_line(fd);
		if (!s2)
			free (s2);
	}
	return (s1);
}

static int	check_fd(char *name_map)
{
	int	path_map;

	if (!name_map)
		perror("Error file descriptor.");
	path_map = open(name_map, O_RDONLY);
	if (path_map == -1)
		perror("Error file descriptor.");
	return (path_map);
}

t_stray	*extract_map(char *name_map)
{
	char	*final_line;

	check_fd(name_map);
	join_line(check_fd(name_map));
	final_line = join_line(check_fd(name_map));
	final_line = del_return_line(final_line);
	ft_printf("%s\n", final_line);
	close(check_fd(name_map));
	return (0);
}
