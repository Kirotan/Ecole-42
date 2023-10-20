/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:56:17 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/20 12:14:38 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && src == NULL)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (n > i)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	char	dest[] = "ABCDEFGHIJKL";
	char	src[] = "CBA";
	size_t	n;

	n = 3;
	printf("Sour : %s\n", src);
	printf("Buffer : %ld\n\n", n);
	printf("Avant ");
	printf("Dest : %s", dest);
	ft_memmove(dest, src, n);
	printf("\nApres ");
	printf("Dest : %s\n", dest);
	return (0);
}
