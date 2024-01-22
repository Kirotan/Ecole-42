/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/22 19:26:05 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(int fd)
{
	int		nb_line;

	nb_line = 0;
	while (get_next_line(fd) > 0)
		nb_line++;
	close (fd);
	return (nb_line);
}

int	**extract_array(char *name_map)
{
	int		**array;
	int		path_image;
	char	*path;
	char	*current_line;
	size_t	i;
	size_t	nb_line;

	path = ft_strlcat("../test_maps/", name_map, ft_strlen(name_map));
	path_image = open(path, O_RDONLY);
	if (path_image == -1)
		perror("Error opening file.");
	nb_line = count_lines(path_image);
	path_image = open(path, O_RDONLY);
	array = (char **)ft_calloc(sizeof(char *) * nb_line);
	if (!array)
	{
		perror("Error memory allocation.");
		close (path_image);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < nb_line && get_next_line (path_image) > 0)
	{
		current_line = get_next_line(path_image);
		array[i] = ft_split_int(current_line, " ");
		free(current_line);
		i++;
	}
	close (path_image);
	return (array);
}
