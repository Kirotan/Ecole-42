/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:14 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/24 15:53:33 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char data[] = { 'a', 'b', 'c', 'd', 0, 'e', 'f' };
    size_t len = ft_strlen(data);

    char testChar = 'd';
    char *result = (char *) ft_memchr(data, testChar, len);
    char *expected = (char *) ft_memchr(data, testChar, len);

    if (result == expected) {
        printf("Test avec '%c' reussi!\n", testChar);
    } else {
        printf("Test avec '%c' echoue!\n", testChar);
    }

    testChar = 'z';
    result = (char *) ft_memchr(data, testChar, len);
    expected = (char *) ft_memchr(data, testChar, len);

    if (result == expected) {
        printf("Test avec '%c' reussi!\n", testChar);
    } else {
        printf("Test avec '%c' echoue!\n", testChar);
    }

    return 0;
}*/
