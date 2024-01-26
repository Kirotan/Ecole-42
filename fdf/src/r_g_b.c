/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_g_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:29:06 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 20:40:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*find_color(char *temp)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*color;

	i = 0;
	j = 0;
	k = 0;
	color = NULL;
	while (temp[i] && temp[i] != 'x')
		i++;
	if (temp[i] && temp[i] == 'x')
		i++;
	k = i;
	while (temp[i++])
		j++;
	if (j > 0)
		color = (char *)ft_calloc(sizeof(char), j + 1);
	if (!color)
		return (NULL);
	j = 0;
	while (temp[k])
		color[j++] = temp[k++];
	color[j] = '\0';
	return (color);
}

void	r_g_b(char *temp, t_stray *array, t_coordinates coord)
{
	char	*color;
	(void)array;
	(void)coord;

	color = find_color(temp);
	ft_printf("%s\n", color);
}
