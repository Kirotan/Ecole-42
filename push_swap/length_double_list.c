/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_double_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:12 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/05 17:28:27 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	length_double_list(t_dlist **dl_a)
{
	size_t	length;
	t_dlist	*tmp;
	long	start;

	if (!dl_a)
		return (0);
	if (!(*dl_a))
		return (0);
	length = 2;
	tmp = *dl_a;
	start = tmp->data;
	tmp = tmp->dl_next;
	while (start != tmp->data)
	{
		tmp = tmp->dl_next;
		if (start == tmp->data)
			return (length);
		length++;
	}
	return (0);
}
