/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:47:09 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/08 15:23:41 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(int nb_param, t_dlist **dl_a, t_dlist **dl_b)
{
	if (nb_param == 3)
	{
		sort_three_a(dl_a);
	}
	if (nb_param == 5)
	{
		sort_five(dl_a, dl_b, nb_param);
	}

}
