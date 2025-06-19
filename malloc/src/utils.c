#include "malloc.h"

extern t_zone *g_zones;
extern pthread_mutex_t g_malloc_mutex;

t_zone *find_zone_for_ptr(void *ptr) {

	t_zone *z = g_zones;

	while (z) {
		if (ptr > (void *)z && (char *)ptr < (char *)z->start + z->total_size) {
			return z;
		}
		z = z->next;
	}

	return NULL;
}
