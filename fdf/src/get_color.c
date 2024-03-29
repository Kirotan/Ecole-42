/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:32:23 by gdoumer           #+#    #+#             */
/*   Updated: 2024/02/05 14:47:21 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_if_color(char *str, int i, int j, char **r)
{
	while (str[i] != '\0')
	{
		if (str[i] == 'x')
			break ;
		else if (str[i + 1] == '\0')
			return ;
		i++;
	}
	j = 0;
	while (*str != 'x' && *str != '\0')
		str++;
	str++;
	*r = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 3);
	if (!*r)
		return ;
	while (*str != '\0')
	{
		(*r)[j] = *str;
		j++;
		str++;
	}
	(*r)[j] = 'f';
	(*r)[j + 1] = 'f';
}

char	*get_color(char *str)
{
	int		j;
	char	*r;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	r = NULL;
	check_if_color(str, i, j, &r);
	return (r);
}
