// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_position_seven.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/11 13:34:46 by gdoumer           #+#    #+#             */
// /*   Updated: 2024/01/15 10:46:24 by gdoumer          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int	ft_position_seven(t_dlist **dl_a, size_t index_pos)
// {
// 	size_t	i;
// 	size_t	res;
// 	t_dlist	*tmp;
// 	size_t	m;

// 	i = 0;
// 	tmp = *dl_a;
// 	m = length_double_list(dl_a);
// 	while (i < m && (tmp->index != index_pos && tmp->index != index_pos + 1
// 		&& tmp->index != index_pos + 2 && tmp->index != index_pos + 3
// 		&& tmp->index != index_pos + 4 && tmp->index != index_pos + 5
// 		&& tmp->index != index_pos + 6))
// 	{
// 		tmp = tmp->dl_next;
// 		i++;
// 	}
// 	res = i;
// 	i = 0;
// 	tmp = *dl_a;
// 	while (i < m && (tmp->index != index_pos && tmp->index != index_pos + 1
// 		&& tmp->index != index_pos + 2 && tmp->index != index_pos + 3
// 		&& tmp->index != index_pos + 4 && tmp->index != index_pos + 5
// 		&& tmp->index != index_pos + 6))
// 	{
// 		tmp = tmp->dl_prev;
// 		i++;
// 	}
// 	if (i < res)
// 		return (0);
// 	return (1);
// }
