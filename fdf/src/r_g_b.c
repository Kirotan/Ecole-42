/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_g_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:29:06 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/26 20:19:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	r_g_b(char *temp, t_stray *array, t_coordinates coord)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*color;
	(void)array;
	(void)coord;

	i = 0;
	j = 0;
	k = 0;
	color = NULL;
	while (temp[i] && temp[i] != 'x')
		i++;
	if (temp[i] && temp[i] == 'x')
		i++;
	k = i;
	while (temp[i])
	{
		i++;
		j++;
	}
	if (j > 0)
		color = (char *)ft_calloc(sizeof(char), j + 1);
	if (!color)
		return ;
	j = 0;
	while (temp[k])
	{
		color[j] = temp[k];
		j++;
		k++;
	}
	ft_printf("%s\n", color);
}
