/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:01 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/30 15:04:59 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		new = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = new;
	}
	*lst = NULL;
}
