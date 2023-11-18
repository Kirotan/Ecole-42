/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/18 14:24:47 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *add_buf_to_stash(int fd, char *buf, char **stash);
char    *clean_stach(int fd, char **stash);

char	*read_and_buf(int fd, char *buf, char **stash)
{
	int			readed;

	if(BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	readed = 0;
	while(readed >= 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		if (!(stash[fd] == add_buf_to_stash(fd, buf, stash)))
			break;
	}
	return (stash[fd]);
}

char	*add_buf_to_stash(int fd, char *buf, char **stash)
{
	char	*tmp;
	char	*new_stash;

	if (!stash[fd])
	{
		stash[fd] = ft_strdup(buf);
		if (!stash[fd])
			return (NULL);
	}	
	else
	{
		tmp = ft_strdup(stash[fd]);
		if (!tmp)
			return (NULL);
		new_stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!new_stash)
			return (NULL);
		free(stash[fd]);
		stash[fd] = new_stash;
	}
	if (ft_strchr(buf, '\n'))
		return (NULL);
	return (stash[fd]);
}

char	*clean_stash(int fd, char **stash)
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
	time = ft_substr(stash[fd], end, ft_strlen(stash[fd] + end));
	if (!time)
	{
		free(line);
		return (NULL);
	}
	free(stash[fd]);
	stash[fd] = time;
	if (!stash[fd])
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*final_line;
	static char	*stash[1024];

	final_line = NULL;
	if (stash[fd] == NULL)
	{
		stash[fd] = ft_calloc(1, 1);
		if (stash[fd] == NULL)
			return (NULL);
	}
	final_line = read_and_buf(fd, NULL, stash);
	if (!final_line || final_line[0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	final_line = clean_stash(fd, stash);
	return (final_line);
}

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s test.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur d'ouverture du fichier");
        return EXIT_FAILURE;
    }

    printf("Commence a lire les lignes depuis le fichier: %s\n", argv[1]);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lu: %s", line);
        free(line);
    }

    if (close(fd) == -1)
    {
        perror("Erreur, fermeture du fichier.");
        return EXIT_FAILURE;
    }

    printf("Fin de lecture du fichier.\n");

    return EXIT_SUCCESS;
}
