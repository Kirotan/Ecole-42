/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_xx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:25:31 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/10 14:42:35 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_puthex(int tmp)
{
	int	len;

	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp / 16;
	}
	return (len);		
}

void	ft_puthex(int tmp)
{
	long	nb;

	nb = tmp;
	if (nb >= 16)
	{
		ft_puthex((nb / 16), str, i);
		ft_puthex((nb % 16), str, i);
	}
	else if ()
		ft_putchar_fd(nb);
}

int	ft_write_args_xx(va_list args, const char *str, int *i)
{
	int	tmp;

	tmp = va_list(args, int);
	if (tmp == 0)
		return (ft_putchar_fd('0', 1));
	ft_puthex(tmp, str, i);
	return (ft_len_puthex(tmp));
}
