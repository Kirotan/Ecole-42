/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:42:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/23 14:57:24 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s;
	int		c;
	char		*result;

	s = "Je cherche une lettre.";
	c = 'u';
	printf("Phrase : %s\n", s);
	printf("Lettre cherchee : %c\n", c);
	result = ft_strchr(s, c);
	if (result)
		printf("Lettre trouvee a : %s\n", result);
	else
		printf("Lettre non trouvee.\n");
	return (0);
}*/
