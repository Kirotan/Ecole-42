/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:03:59 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/06 21:03:30 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*str;

	str = "Oh my ZSH";
	ft_printf("Test tres %simple !", str);
	printf("Test tres %simple !", str);
	return (0);
}
