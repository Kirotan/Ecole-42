/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/21 01:11:32 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_buf_to_stash(int fd, char *buf, char **stash);
char	*clean_stach(int fd, char **stash);

char	*read_and_buf(int fd, char *buf, char **stash)
{
	int			readed;

	readed = 1;
	while (readed >= 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(stash[fd]);
			return (NULL);
		}
		stash[fd] = add_buf_to_stash(fd, buf, stash);
		if (stash[fd] && (ft_strchr(stash[fd], '\n') || readed == 0))
			return (stash[fd]);
	}
	return (NULL);
}

char	*add_buf_to_stash(int fd, char *buf, char **stash)
{
	char	*new_stash;

	if (!stash[fd])
		stash[fd] = ft_strdup(buf);
	else
	{
		new_stash = ft_strjoin(stash[fd], buf);
		free(stash[fd]);
		stash[fd] = new_stash;
	}
	return (stash[fd]);
}

char	*clean_stash(int fd, char **stash)
{
	int		end;
	char	*line;
	char	*time;

	end = 0;
	if (!stash[fd])
		return (NULL);
	while (stash[fd][end] && stash[fd][end] != '\n')
		end++;
	if (stash[fd][end] == '\n')
		end++;
	line = ft_substr(stash[fd], 0, end);
	time = ft_substr(stash[fd], end, ft_strlen(&stash[fd][end]));
	free(stash[fd]);
	stash[fd] = time;
	if (!line || !time || ft_strlen(line) == 0)
	{
		free(stash[fd]);
		free(line);
		stash[fd] = NULL;
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*final_line;
	static char	*stash[1024];
	char		*tmp_buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	tmp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	stash[fd] = read_and_buf(fd, tmp_buf, stash);
	free(tmp_buf);
	if (!stash[fd])
		return (NULL);
	final_line = clean_stash(fd, stash);
	return (final_line);
}
