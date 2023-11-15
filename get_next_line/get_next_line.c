/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/15 18:42:27 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Utiliser read pour ajouter les caracteres a la reserve.
char	*read_and_stach(int fd, size_t nbyte)
{
	char		*buf;
	static char	**stach;
	char		*line;
	int			readed;

	if(buffer_size <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = NULL;
	readed = 1;
	while(readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		stash[fd] = strjoin(stash[d], buff);
	}
}

// Ajouter le contenu du buffer a la fin de la reserve
void	add_to_stach()
{

}

// Extrait tous les caracteres depuis la reserve et les stockent dans out_line. Arretez apres le 1er \n rencontre.
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
