/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/23 19:27:56 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(int fd)
{
	int		nb_line;
	char	*tmp;

	nb_line = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free (tmp);
		tmp = get_next_line(fd);
		nb_line++;
	}
	close (fd);
	return (nb_line);
}

int	**extract_array(char *name_map)
{
	int		**array;
	int		path_image;
	char	*current_line;
	size_t	i;
	size_t	nb_line;

	path_image = open(name_map, O_RDONLY);
	if (path_image == -1)
		perror("Error opening file.");
	nb_line = count_lines(path_image);
	path_image = open(name_map, O_RDONLY);
	array = (int **)ft_calloc(sizeof(int *) * nb_line, 0);
	if (!array)
	{
		perror("Error memory allocation.");
		close (path_image);
		return (0);
	}
	i = 0;
	while (i < nb_line)
	{
		current_line = get_next_line(path_image);
		array = ft_split_int(current_line, ' ', i);
		free(current_line);
		i++;
	}
	close (path_image);
	return (array);
}
