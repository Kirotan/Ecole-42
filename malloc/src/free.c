#include "malloc.h"

extern t_zone			*g_zones;
extern pthread_mutex_t	g_malloc_mutex;


static t_block *merge_with_next(t_block *block) {
	t_block	*next = block->next;
	if (next && next->free) {
		block->size += ALIGN(sizeof(t_block)) + next->size;
		block->next = next->next;
	}
	return block;
}

static int zone_is_empty(t_zone *zone) {
	t_block	*b = zone->blocks;
	while (b) {
		if (b->free == 0)
			return 0;
		b = b->next;
	}
	return 1; //retourne 1 si tous les blocs sont libres
}


static int count_zones(t_type type) {
	t_zone	*z = g_zones;
	int	count = 0;

	while (z) {
		if (z->type == type)
			count++;
		z = z->next;
	}
	return count;
}


static void remove_zone(t_zone *zone) {
	t_zone	*prev = NULL;
	t_zone	*cur  = g_zones;
	while (cur && cur != zone) {
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return;
	if (!prev)
		g_zones = cur->next;
	else
		prev->next = cur->next;
	munmap(cur->start, cur->total_size);
}

void free(void *ptr) {
	t_zone	*zone;
	t_block	*block, *prev_block;

	if (!ptr)
		return;

	pthread_mutex_lock(&g_malloc_mutex);

	zone = find_zone_for_ptr(ptr);
	if (!zone) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return;
	}

	if (zone->type == LARGE) {
		remove_zone(zone);
		pthread_mutex_unlock(&g_malloc_mutex);
		return;
	}

	//chercher bloc dans zone->blocks
	prev_block = NULL;
	block = zone->blocks;
	while (block) {
		if (block->data == ptr)
			break;
		prev_block = block;
		block = block->next;
	}
	if (!block) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return;
	}

	block->free = 1;
	block = merge_with_next(block);

	if (prev_block && prev_block->free)
		block = merge_with_next(prev_block);

	if (zone_is_empty(zone) && count_zones(zone->type) > 1)
		remove_zone(zone);


	pthread_mutex_unlock(&g_malloc_mutex);
}
