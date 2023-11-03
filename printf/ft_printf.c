/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:29:04 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/03 11:29:04 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	verif_charac(char c)
{
	if (c && c != '%')
			ft_putchar_fd(c, 1);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	while (*format)
	{
		verif_charac(*format);
		count++;
		format++;
	}
	va_end(args);
	return (count);
}
