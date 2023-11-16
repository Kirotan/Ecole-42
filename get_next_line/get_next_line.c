/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/16 17:09:33 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_buf(int fd, char *buf, char **stash)
{
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

char	*add_buf_to_stash(int fd, char *buf, char **stash)
{
	char	*tmp;
	char	*new_stash;

	if (!stash[fd])
	{
		stash[fd] = strdup(buf);
		if (!stash[fd])
			return (NULL);
	}	
	else
	{
		tmp = strdup(stash[fd]);
		if (!tmp)
			return (NULL);
		new_stash = strjoin(tmp, buf);
		free(tmp);
		if (!new_stash)
			return (NULL);
		free(stash[fd]);
		stash[fd] = new_stash;
	}
	if (strchr(buf, '\n'))
		return (NULL);
	return (stash[fd]);
}

char	*clean_stach(int fd, char **stash)
{
	int		end;
	char	*line;
	char	*time;

	end = 0;
	while (stash[fd][end] && stash[fd][end] != '\n')
		end++;
	if (stash[fd][end] && stash[fd][end] == '\n')
		end++;
	line = ft_substr(stash[fd], 0, end);
	if (!line)
		return (NULL);
	time = ft_substr(stash[fd], end, ft_strlen((stash[fd]) - end));
	if (!time);
		return (NULL);
	free(stash[fd]);
	stash[fd] = time;
	if (!stash[fd])
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{

}

int	main(void)
{
	
	return (0);
}
