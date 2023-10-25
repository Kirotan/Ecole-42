/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:44:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/25 14:50:10 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	int		j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	j = start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (s[j] != '\0' && i < len)
	{
		ptr[i] = s[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char			s[] = "Phrase a copier.";
	unsigned int	start;
	size_t			len;
	char			*result;

	start = 0;
	len = 11;
	result = ft_substr(s, start, len);
	printf("Resultat : %s\n", result);
	return (0);
}*/
