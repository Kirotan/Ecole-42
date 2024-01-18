/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:14:38 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/17 14:43:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_median(int nb_param, size_t median, t_dlist **a, t_dlist **b)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	while (i++ < nb_param)
	{
		if ((*a)->index <= median)
		{
			k = (size_t)j;
			push_b(a, b);
			if ((size_t)j++ == median)
				break ;
			else if (k != (size_t)j)
				continue ;
		}
		rotate_a(a);
	}
}

void	sort_five(t_dlist **dl_a, t_dlist **dl_b, int nb_param)
{
	size_t	median;

	median = nb_param / 2;
	sort_five_median(nb_param, median, dl_a, dl_b);
	sort_three_a(dl_a);
	if ((*dl_b)->index < (*dl_b)->dl_next->index)
		swap_b(dl_b);
	sort_three_a(dl_a);
	push_a(dl_a, dl_b);
	push_a(dl_a, dl_b);
}
