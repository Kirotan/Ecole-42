/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:17:31 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/23 14:04:06 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	i = 0;
	d = ft_strlen(dst);
	if (size <= d)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && (d + i) < (size -1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + ft_strlen(src));
}
/*
int	main(void)
{
	size_t	size = 26;
	char	dst[size];
	char	src[] = "de la fin.";

	ft_strlcpy(dst, "C'est le debut ", 16);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);
	ft_strlcat(dst, src, size);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);
	return (0);
}*/
