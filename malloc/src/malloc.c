#define _GNU_SOURCE
#include "malloc.h"

t_zone *g_zones = NULL; //zone globale en liste chainee
pthread_mutex_t g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER; //Verrou pour proteger l'acces a g_zones en cas de multithreading

static t_type get_type(size_t size) {
	if (size <= TINY_MAX)
		return TINY;
	else if (size <= SMALL_MAX)
		return SMALL;
	return LARGE;
}


static size_t zone_size(t_type type) {
	if (type == TINY)
		return TINY_ZONE_SIZE;
	if (type == SMALL)
		return SMALL_ZONE_SIZE;
	return ALIGN(sizeof(t_block) + SMALL_MAX);
}


static t_zone *create_zone(t_type type, size_t size) {
	size_t total_size;
	if (type == LARGE)
		total_size = ALIGN( ALIGN(sizeof(t_zone)) + ALIGN(sizeof(t_block)) + size );
	else
		total_size = zone_size(type);

	void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return NULL;

	t_zone *zone = (t_zone *)ptr;
	zone->type = type;
	zone->total_size = total_size;
	zone->start = ptr;
	zone->next  = NULL;

	// premier bloc
	zone->blocks = (t_block *)((char *)ptr + ALIGN(sizeof(t_zone)));
	zone->blocks->size = size;
	zone->blocks->free = 0;
	zone->blocks->next = NULL;
	zone->blocks->data = (void *)((char *)zone->blocks + ALIGN(sizeof(t_block)));

	return zone;
}


static t_block *find_free_block(t_zone *zone, size_t size) {
	t_block *block = zone->blocks;
	while (block) {
		if (block->free && block->size >= size)
			return block;
		block = block->next;
	}
	return NULL;
}


static t_block *allocate_block(t_zone *zone, size_t size) {
	t_block *block = find_free_block(zone, size);
	if (block) {
		block->free = 0;
		return block;
	}

	block = zone->blocks;
	while (block->next)
		block = block->next;

	void *new_block_addr = (char *)block->data + ALIGN(block->size);
	if ((char *)new_block_addr + ALIGN(sizeof(t_block)) + size > (char *)zone->start + zone->total_size)
		return NULL;

	t_block *new_block = (t_block *)new_block_addr;
	new_block->size = size;
	new_block->free = 0;
	new_block->next = NULL;
	new_block->data = (void *)((char *)new_block + ALIGN(sizeof(t_block)));

	block->next = new_block;
	return new_block;
}


void *malloc(size_t size) {
	if (size == 0){
		return NULL;
	}

	pthread_mutex_lock(&g_malloc_mutex);

	size = ALIGN(size);
	t_type type = get_type(size);
	t_zone *zone = g_zones;
	t_block *block = NULL;

	//cherche un bloc libre dans zones existantes du bon type
	while (zone) {
		if (zone->type == type) {
			block = allocate_block(zone, size);
			if (block)
				break;
		}
		zone = zone->next;
	}

	//si aucun bloc libre creeation nouvelle zone
	if (!block) {
		t_zone *new_zone = create_zone(type, size);
		if(!new_zone) {
			pthread_mutex_unlock(&g_malloc_mutex);
			return NULL;
		}
		new_zone->next = g_zones;
		g_zones = new_zone;
		block = new_zone->blocks;
	}

	pthread_mutex_unlock(&g_malloc_mutex);
	return block->data;
}
