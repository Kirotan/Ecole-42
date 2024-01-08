/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:38 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/08 16:08:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_dlist **dl_a, t_dlist **dl_b, int nb_param)
{
	size_t	median;
	int		i;
	int		j;
	size_t	k;

	median = nb_param / 2;
	i = 0;
	j = 0;
	while (i < nb_param)
	{
		printf("%ld\n", (*dl_a)->index);
		if ((*dl_a)->index <= median)
		{
			k = (size_t)j;
			push_b(dl_a, dl_b);
			j++;
			if ((size_t)j == median)
				break ;
			else if (k != (size_t)j)
				continue ;
		}
		rotate_a(dl_a);
		i++;
	}
	sort_three_a(dl_a);
	if ((*dl_b)->index < (*dl_b)->dl_next->index)
		swap_b(dl_b);
	sort_three_a(dl_a);
}
