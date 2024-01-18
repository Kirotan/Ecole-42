/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/17 12:55:47 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_mini_value(t_dlist **dl_a, size_t length)
{
	size_t	j;
	t_dlist	*tmp;
	long	mini_value;

	j = 0;
	tmp = (*dl_a);
	mini_value = tmp->data;
	while (j < length)
	{
		if (!tmp->index)
			mini_value = tmp->data;
		tmp = tmp->dl_next;
		j++;
	}
	j = 0;
	tmp = (*dl_a);
	while (j < length)
	{
		if (tmp->data < mini_value && !tmp->index)
			mini_value = tmp->data;
		tmp = tmp->dl_next;
		j++;
	}
	return (mini_value);
}

void	create_index(t_dlist **dl_a, size_t length)
{
	size_t	index;
	long	minimal_value;
	size_t	i;
	size_t	k;

	index = 1;
	i = 0;
	while (i < length)
	{
		minimal_value = find_mini_value(dl_a, length);
		k = 0;
		while (k < length)
		{
			if (minimal_value == (*dl_a)->data)
				(*dl_a)->index = index;
			(*dl_a) = (*dl_a)->dl_next;
			k++;
		}
		index ++;
		i++;
	}
}
