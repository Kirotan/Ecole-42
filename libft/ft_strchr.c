/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:42:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/24 12:44:46 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
int	main(void)
{
	const char	*s;
	int		c;
	char		*result;

	s = "Je cherche une lettre.";
	c = 1024;
	printf("Phrase : %s\n", s);
	printf("Lettre cherchee : %c\n", c);
	result = ft_strchr(s, c);
	if (result)
		printf("Lettre trouvee a : %s\n", result);
	else
		printf("Lettre non trouvee.\n");
	return (0);
}*/
