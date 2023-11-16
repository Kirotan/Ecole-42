/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/16 16:02:51 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Utiliser read pour ajouter les caracteres au buffer.
char	*read_and_buf(int fd)
{
	char		*buf;
	static char	**stash;
	int			readed;

	if(buffer_size <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE);
	readed = 1;
	while(readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		if (!(stash == add_buf_to_stash(fd, buf, stash)))
			break;
	}
	return (*stash);
}

// Ajouter le contenu du buffer a la fin de la reserve
char	*add_buf_to_stash(int fd, char *buf, char **stash)
{
	char	*tmp;
	char	*new_stash;

	if (!stash[fd])
	{
		stash[fd] = strdup(buff);
		if (!stash[fd])
			return (NULL);
	}	
	else
	{
		tmp = strdup(stash[fd]);
		if (!tmp)
			return (NULL);
		new_stash = strjoin(tmp, buff);
		free(tmp);
		if (!new_stach)
			return (NULL);
		free(stash[fd]);
		stash[fd] = new_stash;
	}
	if (strchr(buf, '\n'))
		return (NULL);
	return (stash[fd]);
}

// Extrait tous les caracteres depuis la reserve et les stockent dans new_line. Arretez apres le 1er \n rencontre.
void	extract_line()
{

}

// Nettoie la reserve de sorte que seuls les caracteres qui n'ont pas ete retrounes a la fin de get_next_line reste dans la static reserve.
void	clean_stach
{

}

char	*get_next_line(int fd)
{

}

int	main(void)
{
	
	return (0);
}
