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

void	recognize_type(char *str, int i)
{
	if (str[i] && str[i] == '%')
		ft_putchar_fd('%', 1);
}

int	verif_charac(char *str, int i)
{
	int	i;

	i = 0;
	if (str[i] && str[i] != '%')
		ft_putchar_fd(str[i], 1);
	else if (str[i] && str[i] == '%')
	{
		i++;
		recognize_type(str, i);
	}
	else
		return (i);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += 
	}
	va_end(args);
	return (count);
}
