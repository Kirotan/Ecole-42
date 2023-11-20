/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:35 by gdoumer           #+#    #+#             */
/*   Updated: 2023/11/20 19:53:55 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

	line = get_next_line(798);
	if (line) free(line);
	return;

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
        printf("Ligne lu: [%s]", line);
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
