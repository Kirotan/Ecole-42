#include "malloc.h"
#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <stdbool.h>

extern t_zone			*g_zones;
extern pthread_mutex_t	g_malloc_mutex;

static void print_ptr(void *p) {
	printf("0x%" PRIxPTR, (uintptr_t)p);
}

void show_alloc_mem(void) {

	size_t	total;
	t_type	types[] = { TINY, SMALL, LARGE }; // Ordre affichage voulu
	t_type	want;
	bool	header_printed;
	t_block	*b;
	char	*buf;

	pthread_mutex_lock(&g_malloc_mutex);

	// si aucune allocation faite
	if (!g_zones) {
		write(1, "Total : 0 bytes\n", 17);
		pthread_mutex_unlock(&g_malloc_mutex);
		return;
	}

	total = 0;
	// Ordre affichage voulu
	const char *names[] = { "TINY :", "SMALL:", "LARGE:" };

	for (int ti = 0; ti < 3; ti++) {
		want = types[ti];
		header_printed = false;

		for (t_zone *z = g_zones; z; z = z->next) {
			if (z->type != want)
				continue;

			// afficher le type une seule fois
			if (!header_printed) {
				printf("%s\n", names[ti]);
				header_printed = true;
			}

			// Affiche l'adresse de début de zone
			print_ptr(z->start);
			printf("\n");

			// Parcours des blocs dans la zone
			for (b = z->blocks; b; b = b->next) {
				void *start = b->data;
				void *end   = (char *)b->data + b->size;
				print_ptr(start);
				printf(" - ");
				print_ptr(end);
				printf(" : %zu bytes\n", b->size);
				total += b->size;
			}
		}
	}

	// Total global
	printf("Total : %zu bytes\n", total);

	pthread_mutex_unlock(&g_malloc_mutex);
}
