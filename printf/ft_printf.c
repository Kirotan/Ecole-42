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

int	write_args(va_list args)
{
	char	*tmp;
	int		k;

	k = 0;
	tmp = va_arg(args, char *);
	while (tmp[k])
	{
		ft_putchar_fd(tmp[k], 1);
		k++;
	}
	return (k);
}

int	recognize_char(const char *str, int *i, va_list args)
{
	int	j;

	j = 0;
	while (str[*i] && str[*i] != 's')
	{
		(*i)++;
		j++;
	}
	if (str[*i] == '\0')
	{
		return (*i - j);
	}
	if (str[*i] == 's')
	{
		write_args(args);
		(*i) = (*i) + j;
		return (*i);
	}
	return (*i);
}

int	verif_char(const char *str, int *i, va_list args)
{
	if (str[*i] && str[*i] == '%')
		return (recognize_char(str, i, args));
	else
		ft_putchar_fd(str[*i], 1);
	return (*i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		h;
	va_list	args;

	i = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		h = verif_char(format, &i, args);
		i++;
	}
	va_end(args);
	printf("\nNombre char :%d\n", i);
	return (i + h);
}
