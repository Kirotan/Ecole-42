/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:17:31 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/23 16:06:08 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strlcat_char(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	i = 0;
	d = ft_strlen(dst);
	if (size <= d)
		return (NULL);
	while (src[i] != '\0' && (d + i) < (size -1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (dst);
}
