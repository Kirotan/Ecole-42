/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:15:20 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/07 12:54:43 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(const char *str, int *i, va_list args)
{
	(*i)++;
	if (str[*i] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (str[*i] == 'c')
		return (ft_write_args_c(args));
	return (-1);
}

int	verif_char(const char *str, int *i, va_list args)
{
	int	h;
	int	l;

	h = 0;
	l = 0;
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			h = ft_sort(str, i, args);
			if (h == -1)
				return (-1);
			l += h;
		}
		else
		{
			h = ft_putchar_fd(str[*i], 1);
			if (h == -1)
				return (-1);
			l+= h;
		}
		(*i)++;
	}
	return (*i + l);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	i = verif_char(format, &i, args);
	va_end(args);
	return (i);
}
