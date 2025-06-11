#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include "../libft/libft.h"

typedef enum e_type {
	TINY,
	SMALL,
	LARGE
} t_type;

#define ALIGNMENT 16
#define ALIGN(x) (((x) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

#define TINY_MAX 128
#define SMALL_MAX 1024
#define TINY_ZONE_SIZE (getpagesize() * 16)
#define SMALL_ZONE_SIZE (getpagesize() * 128)

typedef struct s_block {
	size_t			size;
	int				free;
	struct s_block	*next;
	void			*data;
} t_block;

typedef struct s_zone {
	t_type			type;
	size_t			total_size;
	struct s_zone	*next;
	t_block			*blocks;
	void			*start;
} t_zone;

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void show_alloc_mem(void);
t_zone *find_zone_for_ptr(void *ptr);


#endif
