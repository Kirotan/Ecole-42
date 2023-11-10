/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_bigx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:25:31 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/10 16:48:05 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_puthex(unsigned int tmp)
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

static void	ft_puthex(unsigned int tmp, char cha)
{

	if (tmp >= 16)
	{
		ft_puthex((tmp / 16), cha);
		ft_puthex((tmp % 16), cha);
	}
	else
	{
		if (tmp < 10)
			ft_putchar_fd((tmp + '0'), 1);
		else
			ft_putchar_fd((tmp - 10 + cha), 1);
	}
}
int	ft_write_args_x(int args, char cha)
{
	if (args == 0)
		return (ft_putchar_fd('0', 1));
	ft_puthex(tmp, cha);
	return (ft_len_puthex(tmp));
}
