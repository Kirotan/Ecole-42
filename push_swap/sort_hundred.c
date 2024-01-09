/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:52:21 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/09 17:10:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_dlist **dl_a, t_dlist **dl_b)
{
	size_t	index_pos;
	size_t	len_a;
	size_t	average_a;
	size_t	average_b;
	size_t	len_b;

	index_pos = 1;
	len_a = length_double_list(dl_a);
	len_b = length_double_list(dl_b);
	average_a = position_averag(dl_a, len_a, index_pos);
	average_b = position_averag(dl_b, len_b, index_pos);
}
