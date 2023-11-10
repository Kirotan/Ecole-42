/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:17:12 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/10 16:48:34 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flag
{
	char	*s;
	int		i;
	int		k;
}	t_flag;

int	ft_printf(const char *format, ...);
int	ft_write_args_c(va_list args);
int	ft_write_args_d(va_list args);
int	ft_write_args_u(va_list args);
int	ft_write_args_percent(char c);
int	ft_write_args_x(int args, char cha);

#endif
