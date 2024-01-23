/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:48:04 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/23 19:21:35 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

static int	**allocate_memory(size_t count)
{
	int	**tab;

	tab = (int **)ft_calloc(sizeof(int *), (count + 1));
	if (!tab)
		return (NULL);
	tab[0] = NULL;
	return ((int **) tab);
}

static void	unblock(int **tab)
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

static void	loop(unsigned int i, size_t start, char *substr, char const *s)
{
	size_t	k;

	k = 0;
	while (k < i - start)
	{
		substr[k] = s[start + k];
		k++;
	}
	substr[i - start] = '\0';
}

static int	**divide(char const *s, char c, int **tab, size_t row)
{
	unsigned int		i;
	int					j;
	size_t				start;
	char				*substr;

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
			substr = NULL;
			loop(i, start, substr, s);
			tab[row][j] = ft_atoi(substr);
			free(substr);
			if (!tab[j] && s[start])
			{
				unblock(tab);
				return (0);
			}
			j++;
		}
	}
	return (tab);
}

int	**ft_split_int(char const *s, char c, size_t row)
{
	size_t	count;
	int		**tab;

	count = ft_count_words(s, c);
	tab = allocate_memory(count);
	if (!tab)
		return (0);
	if (!divide(s, c, tab, row))
	{
		return (0);
	}
	return (tab);
}
