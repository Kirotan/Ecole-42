/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:03:59 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/07 15:37:31 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str;
	char	*str2;

	str = "Oh my ZSH";
	str2 = "test";
	ft_printf("Test tres %simple !%s", str, str2);
	printf("Test tres %simple !%s", str, str2);
	return (0);
}
