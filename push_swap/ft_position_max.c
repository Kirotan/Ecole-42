/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:34:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/11 13:37:42 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position_max(t_dlist **dl_a, size_t index_pos)
{
	int		i;
	int		res;
	t_dlist	*tmp;

	i = 0;
	res = 100;
	tmp = *dl_a;
	while (tmp->index != index_pos && tmp->index != index_pos + 1
		&& tmp->index != index_pos + 2 && tmp->index != index_pos + 3
		&& tmp->index != index_pos + 4)
	{
		tmp = tmp->dl_next;
		i++;
	}
	res = i;
	i = 0;
	tmp = *dl_a;
	while (tmp->index != index_pos && tmp->index != index_pos + 1
		&& tmp->index != index_pos + 2 && tmp->index != index_pos + 3
		&& tmp->index != index_pos + 4)
	{
		tmp = tmp->dl_prev;
		i++;
	}
	if (i < res)
		return (0);
	return (1);
}
