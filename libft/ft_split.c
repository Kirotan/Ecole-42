/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:48:04 by gdoumer           #+#    #+#             */
/*   Updated: 2023/10/31 15:46:04 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	count;
	
	if (!s || !c)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	printf("Nombre de mot(s) : %zu\n", count);
	return (count);
}

static char	**allocate_memory(size_t count)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	return ((char **) tab);
}

static void	unblock(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char **divide(char const *s, char c, char **tab)
{
	unsigned int		i;
	int					j;
	size_t				end;

	i = 0;
	j = 0;
	while (s[i])
	{
		end = 0;
		j = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				end++;
				i++;
			}
		}
		if (!(tab[j] = ft_substr(s, i, end)))
			unblock(tab);
		printf("Mot : %s\n", tab[j]);
		j++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tab;

	count = count_words(s, c);
	tab = allocate_memory(count);
	divide(s, c, tab);
	return (tab);
}

int	main()
{
	char	s[] = "Je surfe sur le code.";
	char	c = ' ';

	ft_split(s, c);
	return (0);
}
