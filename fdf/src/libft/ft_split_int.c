/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:48:04 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/22 19:13:13 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		i;
	size_t	count;

	if (!s)
		return (0);
	if (c == '\0')
	{
		if (*s == '\0')
			return (0);
		else
			return (1);
	}
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
	return (count);
}

static int	**allocate_memory(size_t count)
{
	int	**tab;

	tab = (int **)ft_calloc(sizeof(int *), (count + 1));
	if (!tab)
		return (NULL);
	tab[0] = NULL;
	return ((int **) tab);
}

static void	unblock(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

static int	**divide(char const *s, char c, char **tab)
{
	unsigned int		i;
	int					j;
	size_t				start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			tab[j] = ft_atoi(ft_substr(s, start, i - start));
			if (!tab[j])
			{
				unblock(tab);
				return (NULL);
			}
			j++;
		}
	}
	return (tab);
}

int	**ft_split_int(char const *s, char c)
{
	size_t	count;
	int		**tab;

	count = count_words(s, c);
	tab = allocate_memory(count);
	if (!tab)
		return (0);
	if (!divide(s, c, tab))
	{
		return (0);
	}
	return (tab);
}
