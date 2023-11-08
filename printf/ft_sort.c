/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:00:48 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/08 22:14:01 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(const char *str, int *i, int *j, va_list args)
{
	int x;

	x = 0;
	if (str[*i] == 's')
	{
		*i = *i - *j;
		x = write_args(args);
		*i = *i + *j;
		return (x);
	}
	else if (str[*i] == 'c')
	{
		*i = *i - *j;
		x = write_args(args);
		*i = *i + *j;
		return (x);
	}
	else
		x = -1;
	return (x);
}
