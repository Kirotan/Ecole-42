/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:20:01 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/24 21:20:17 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 1;
	j = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n && ptr1[j] == ptr2[j])
	{
		i++;
		j++;
	}
	return ((int)(ptr1[j] - ptr2[j]));
}
/*
int	main(void)
{
	char	s1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	char	s2[9] = {1, 2, 3, 4, 5, 6, 7, 'z', 'y'};
	size_t	n = 7;
	int	result;

	result = ft_memcmp(s1, s2, n);
	printf("Valeur renvoyee : %d\n", result);
	return (0);
}*/
