/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:13:07 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/19 18:11:56 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struc double_list
{
	int		content;
	int		cost;
	int		index;
	bool	top_middle;
	bool	cheapest;
	struct	dbl_list *target_node;
	struct	dbl_list *prev;
	struct	dbl_list *next;
}	dbl_list;

#endif
