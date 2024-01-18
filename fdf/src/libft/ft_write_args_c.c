/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:46:25 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/03 16:54:36 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_args_c(va_list args)
{
	char	tmp;

	tmp = (char)va_arg(args, int);
	if (ft_putchar_fd(tmp, 1) == -1)
		return (-1);
	return (1);
}
