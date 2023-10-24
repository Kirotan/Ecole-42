/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:13:14 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/24 11:39:48 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	s[] = "Incroyable sur 20.";
	int	c;
	size_t	n;

	c = 'Z';
	n = 7;
	printf ("Avant : %s\n", s);
	printf("Apres :%s\n", (unsigned char *)ft_memset(s, c, n));
	return (0);
}*/
