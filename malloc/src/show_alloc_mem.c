#include "malloc.h"

extern t_zone			*g_zones;
extern pthread_mutex_t	g_malloc_mutex;

static void print_ptr(void *p) {
	printf("0x%" PRIxPTR, (uintptr_t)p);
}

void show_alloc_mem(void) {

	size_t		total;
	int			ti;
	t_zone		*z;
	t_type		want;
	t_block		*b;
	void		*start;
	void		*end;
	bool		header_printed;
	t_type		types[] = { TINY, SMALL, LARGE };
	const char	*names[] = { "TINY :", "SMALL :", "LARGE :" };

	// Si rien alloue dans g_zones
	if (!g_zones) {
		printf("Total : 0 bytes\n");
		return;
	}

	total = 0;

	for (ti = 0; ti < 3; ti++) {
		want = types[ti];
		header_printed = false;

		// Parcours liste g_zones
		for (z = g_zones; z; z = z->next) {
			if (z->type != want)
				continue;

			// afficher le label une fois
			if (!header_printed) {
				printf("%s\n", names[ti]);
				header_printed = true;
			}

			// Affiche l'adresse de début de zone
			print_ptr(z->start);
			printf("\n");

			// Parcours des blocs dans la zone
			for (b = z->blocks; b; b = b->next) {
				start = b->data;
				end = (char *)b->data + b->size;
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

}
