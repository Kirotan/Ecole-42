/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:57:03 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/20 12:12:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && src == NULL)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest[] = "123456789";
	char	src[] = "abcdefghi";
	size_t	n;

	n = 3;
	printf("AVANT\n");
	printf("Sour : %s\n", src);
	printf("Dest : %s\n", dest);
	ft_memcpy(dest, src, n);
	printf("\nAPRES\n");
	printf("Sour : %s\n", src);
	printf("Dest : %s\n", dest);
	return (0);
}
