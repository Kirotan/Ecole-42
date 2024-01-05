/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:38:53 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 21:34:07 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static long	find_mini_value(t_dlist **dl_a, size_t length, long current_value)
{
	size_t	j;
	t_dlist	*tmp;
	long	mini_value;

	j = 0;
	tmp = *dl_a;
	mini_value = current_value;
	while (j < length)
	{
		if (tmp->data < mini_value)
		{
			mini_value = tmp->data;
		}
		tmp = tmp->dl_next;
		j++;
	}
	return (mini_value);
}

void	create_index(t_dlist **dl_a, size_t length)
{
	t_dlist	*tmp;
//	size_t	index;
	long	current_value;
	long	minimal_value;
	size_t	i;

	tmp = *dl_a;
//	index = 0;
	current_value = tmp->data;
	i = 0;
	while (i < length)
	{
		minimal_value = find_mini_value(dl_a, length, current_value);
		printf("%ld\n", minimal_value);
		i++;
	}
}
