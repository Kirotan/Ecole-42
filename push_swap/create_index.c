/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 21:50:55 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static long	find_mini_value(t_dlist **dl_a, size_t length)
{
	size_t	j;
	long	mini_value;

	j = 0;
	mini_value = (*dl_a)->data;
	while (j < length)
	{
		if ((*dl_a)->data < mini_value)
		{
			mini_value = (*dl_a)->data;

		}
		(*dl_a) = (*dl_a)->dl_next;
		j++;
	}
	return (mini_value);
}

void	create_index(t_dlist **dl_a, size_t length)
{
//	size_t	index;
	long	minimal_value;
	size_t	i;

//	index = 0;
	i = 0;
	while (i < length)
	{
		minimal_value = find_mini_value(dl_a, length);
		printf("%ld\n", minimal_value);
		i++;
	}
}
