/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_littlex.c                            :+:      :+:    :+:   */
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
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else if (nb < 10)
	{
		ft_putchar_fd((nb + '0'), 1);
	}
	else
		ft_putchar_fd((nb - 10 + 'a'), 1);
}

int	ft_write_args_littlex(va_list args)
{
	int	tmp;

	tmp = va_arg(args, int);
	if (tmp == 0)
		return (ft_putchar_fd('0', 1));
	if (tmp < 0)
	{
		ft_putchar_fd('-', 1);
		tmp = -tmp;
	}
	ft_puthex(tmp);
	return (ft_len_puthex(tmp));
}
