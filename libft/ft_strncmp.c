/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:51:44 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/24 09:54:03 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "ABCD";
	char	s2[] = "ABCDzGA";
	size_t	n;

	n = 30;
	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
	printf("Valeur retournee : %d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/
