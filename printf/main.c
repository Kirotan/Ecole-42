/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:03:59 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/09 10:13:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			*str;
	int				i;
	unsigned int	ui;

	str = "Oh my ZSH";
	i = 12342;
	ui = 98765678;
	printf("%d\n", ft_printf("Test %simple ;%d %c %%%s %u\n", str, i, 'W', str, ui));
	printf("%d\n", printf("Test %simple ;%d %c %%%s %u\n", str, i, 'W', str, ui));
	fflush(stdout);
}
