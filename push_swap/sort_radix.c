/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:27:20 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/17 14:48:45 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_dlist **double_list)
{
	t_dlist		*head;
	size_t		max;
	size_t		max_bits;
	size_t		i;
	size_t		len;

	head = *double_list;
	max = head->index;
	len = length_double_list(&head);
	max_bits = 0;
	i = 0;
	while (i++ < len)
	{
		if (head->index > max)
			max = head->index;
		head = head->dl_next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_dlist **dl_a, t_dlist **dl_b)
{
	t_dlist		*head_a;
	size_t		i;
	size_t		j;
	size_t		size;
	size_t		max_bits;

	i = 0;
	head_a = *dl_a;
	size = length_double_list(&head_a) - 1;
	max_bits = get_max_bits(dl_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ <= size)
		{
			head_a = *dl_a;
			if (((head_a->index >> i) & 1) == 1)
				rotate_a(dl_a);
			else
				push_b(dl_a, dl_b);
		}
		while (length_double_list(dl_b) != 0)
			push_a(dl_a, dl_b);
		i++;
	}
}
