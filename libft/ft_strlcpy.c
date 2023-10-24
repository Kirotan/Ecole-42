/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:44:45 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/23 13:29:15 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	sizesrc;
	size_t	i;

	i = 0;
	sizesrc = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (sizesrc);
}
/*
int	main(void)
{
	size_t	size = 16;
	char	dst[size];
	char	src[] = "Surfer sur le code.";

	printf("Source : %s\n", src);
	ft_strlcpy(dst, src, size);
	printf("Avec dst(16) : %s\n", dst);	
	return (0);
}*/
