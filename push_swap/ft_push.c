/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:41:44 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/12 17:31:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_dlist **dl_a, t_dlist **dl_b)
{
	t_dlist	*tmp;

	if (!*dl_b)
		return ;
	tmp = *dl_b;
	delete_node(dl_b, *dl_b);
	front_add_double_list(dl_a, tmp);
	ft_printf("pa\n");
}

void	push_b(t_dlist **dl_a, t_dlist **dl_b)
{
	t_dlist	*tmp;

	if (!*dl_a)
		return ;
	tmp = *dl_a;
	delete_node(dl_a, *dl_a);
	front_add_double_list(dl_b, tmp);
	ft_printf("pb\n");
}
