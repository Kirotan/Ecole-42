/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:49:32 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/10 18:09:52 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print(t_dlist *dl_a)
{
	t_dlist	*tmp;

	if (!dl_a)
		return ;
	tmp = dl_a;
	while (tmp->dl_next != dl_a)
	{
		printf("Data : %ld | Index: %ld\n", tmp->data, tmp->index);
		tmp = tmp->dl_next;
	}
	printf("Data : %ld | Index: %ld\n", tmp->data, tmp->index);
	return ;
}
