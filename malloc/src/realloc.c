#include "malloc.h"

extern t_zone			*g_zones;
extern pthread_mutex_t	g_malloc_mutex;

static t_block *find_block_in_zone(t_zone *zone, void *ptr) {

	t_block	*b = zone->blocks;

	while (b) {
		if (b->data == ptr)
			return b;
		b = b->next;
	}
	return NULL;
}

static int try_expand_in_place(t_block *block, size_t new_size) {

	size_t	old_size = block->size;
	t_block	*next = block->next;
	size_t	combined_size;
	size_t	remainder;
	t_block	*new_block;

	if (next && next->free) {
		combined_size = old_size + ALIGN(sizeof(t_block)) + next->size;
		if (combined_size >= new_size) {
			block->size = new_size;
			if (combined_size == new_size) {
				block->next = next->next;
			} else {
				remainder = combined_size - new_size - ALIGN(sizeof(t_block));
				void *new_block_addr = (char *)block->data + new_size;
				new_block = (t_block *)((char *)new_block_addr + remainder);
				new_block->size = next->size - (new_size - old_size);
				new_block->free = 1;
				new_block->next = next->next;
				new_block->data = (void *)((char *)new_block + ALIGN(sizeof(t_block)));
				block->next = new_block;
			}
			return 1;
		}
	}

	return 0;
}

void *realloc(void *ptr, size_t size) {

	t_zone	*zone;
	t_block	*block;
	size_t	old_size;
	void	*new_ptr;

	if (!ptr)
		return malloc(size);

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	size = ALIGN(size);
	pthread_mutex_lock(&g_malloc_mutex);
	zone = find_zone_for_ptr(ptr);
	if (!zone) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return NULL;
	}

	if (zone->type == LARGE) {
		block = zone->blocks; // le premier et unique bloc
		old_size = block->size;

		if (size <= old_size) {
			pthread_mutex_unlock(&g_malloc_mutex);
			return ptr;
		} else {
			pthread_mutex_unlock(&g_malloc_mutex);
			new_ptr = malloc(size);
			if (!new_ptr)
				return NULL;
			ft_memcpy(new_ptr, ptr, old_size);
			free(ptr);
			return new_ptr;
		}
	}

	block = find_block_in_zone(zone, ptr);
	if (!block) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return NULL;
	}

	old_size = block->size;
	if (size == old_size) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return ptr;
	}

	if (size < old_size) {
		block->size = size;
		pthread_mutex_unlock(&g_malloc_mutex);
		return ptr;
	}

	if (try_expand_in_place(block, size)) {
		pthread_mutex_unlock(&g_malloc_mutex);
		return ptr;
	}

	pthread_mutex_unlock(&g_malloc_mutex);

	new_ptr = malloc(size);
	if (!new_ptr)
		return NULL;

	ft_memcpy(new_ptr, ptr, old_size);

	free(ptr);

	return new_ptr;
}
