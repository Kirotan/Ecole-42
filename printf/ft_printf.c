/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:15:20 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/06 21:04:33 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_args(va_list args)
{
	char	*tmp;
	int		k;

	tmp = va_arg(args, char *);
	while (tmp[k])
	{
		ft_putchar_fd(tmp[k], 1);
		k++;
	}
	return (k);
}

int	recognize_char(const char *str, int i, va_list args)
{
	int	j;
	int	n;

	j = 0;
	while (str[i] && str[i] != 's')
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
	{
		return (i - j);
	}
	if (str[i] == 's')
	{
		n = write_args(args);
		return (i + n);
	}
	return (i);
}

int	verif_char(const char *str, int i, va_list args)
{
	int m;

	if (str[i] && str[i] == '%')
		m = recognize_char(str, i, args);
	else
		ft_putchar_fd(str[i], 1);
	return (m);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		h;

	i = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		h = verif_char(format, i, args);
		i++;
	}
	va_end(args);
	printf("%d\n", i);
	return (i + h);
}
