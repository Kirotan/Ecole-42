/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/08 18:41:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b, int nb_param)
{
	int	i;

	i = 0;
	while (i++ < nb_param - 3)
	{
		if (i == 3)
			sort_three_b(dl_b);
		if ((*dl_a)->index > (*dl_a)->dl_next->index)
		{
			swap_a(dl_a);
			push_b(dl_a, dl_b);
		}
		else if ((*dl_a)->index > (*dl_a)->dl_prev->index)
		{
			rotate_a(dl_a);
			push_b(dl_a, dl_b);
		}
		else
			push_b(dl_a, dl_b);
	}
}
