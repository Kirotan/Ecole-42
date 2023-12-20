/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:13:07 by gdoumer           #+#    #+#             */
/*   Updated: 2023/12/20 17:12:59 by gdoumer          ###   ########.fr       */
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

int			main(int argc, char **argv);
int			error_or_not(int argc, char **argv);
dbl_list	*ft_lstnew(void *content);

#endif
