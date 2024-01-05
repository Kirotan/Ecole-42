/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 22:50:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_index(t_dlist **dl_a, long mini_value, size_t *index)
{
	while (*index != (*dl_a)->index)
	{
		if (mini_value == (*dl_a)->data)
		{
			(*dl_a)->index = *index;
			printf("Num : %ld", (*dl_a)->data);
			printf("Index : %ld\n", (*dl_a)->index);
		}
		(*dl_a) = (*dl_a)->dl_next;
	}
}

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
		while ((tmp->index) > 0 && j < length)
		{
			tmp = tmp->dl_next;
			j++;
		}
		if (tmp->data < mini_value)
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

	index = 1;
	i = 0;
	while (i < length)
	{
		minimal_value = find_mini_value(dl_a, length);
		fill_index(dl_a, minimal_value, &index);
		index ++;
		i++;
	}
}
