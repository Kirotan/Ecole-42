/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:48:34 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/19 10:48:34 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

int	main(void)
{
	char	s[] = "Tortue ninja";
	size_t	n;

	n = 1;
	printf("Avant : %s\n", s);
	ft_bzero(s, n);
	printf("Apres : %s\n", s);
	return (0);
}
