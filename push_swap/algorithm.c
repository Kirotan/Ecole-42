/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:47:09 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/12 19:19:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(int nb_param, t_dlist **dl_a, t_dlist **dl_b)
{
	if (nb_param == 2)
		sort_two_a(dl_a);
	if (nb_param == 3)
		sort_three_a(dl_a);
	if (nb_param == 4 || nb_param == 5)
		sort_five(dl_a, dl_b, nb_param);
	if (nb_param >=6 && nb_param <= 100)
		sort_hundred(dl_a, dl_b);
	if (nb_param >= 101 && nb_param <= 500)
		sort_max(dl_a, dl_b);
}
