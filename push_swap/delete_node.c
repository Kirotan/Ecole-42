/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:57:06 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/06 19:13:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_dlist **double_list, t_dlist *node_to_delete)
{
	if (!double_list || !node_to_delete || length_double_list(double_list) == 1)
		return ;
	if (*double_list == node_to_delete)
	{

	}
}
