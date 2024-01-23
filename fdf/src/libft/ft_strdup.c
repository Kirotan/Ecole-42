/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:32:48 by gdoumer           #+#    #+#             */
/*   Updated: 2024/01/23 14:27:14 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
