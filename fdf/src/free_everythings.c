/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everythings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:12:51 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/03 17:48:11 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_everythings(t_stray *array)
{
	int	i;
	int	len;

	i = 0;
	len = array[0].len_total;
	while (i < len)
	{
		free(array[i].color);
		i++;
	}
	free(array);
}
