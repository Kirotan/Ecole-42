/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:38:06 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/23 15:39:07 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (len == 0 && s[len] != (char)c)
		return (NULL);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s;
	int		c;
	char		*result;

	s = "Chercher bateau";
	c = 'e';
	printf("La phrase : %s\n", s);
	printf("Lettre cherchee : %c\n", c);
	result = ft_strrchr(s, c);
	if (result)
		printf("La lettre trouvee : %s\n", result);
	else
		printf("Pas d'occurence.\n");
	return (0);
}*/
