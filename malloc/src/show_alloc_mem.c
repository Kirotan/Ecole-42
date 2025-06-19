#include "malloc.h"
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/libft.h"

extern t_zone			*g_zones;
extern pthread_mutex_t	g_malloc_mutex;

static void	safe_write(const char *s, size_t len) {

	size_t	written = 0;
	ssize_t	ret;

	while (written < len) {
		ret = write(1, s + written, len - written);
		if (ret <= 0) break;
		written += ret;
	}
}

// Affiche p en hexadecimal 64bits
static void	print_ptr(void *p) {

	uintptr_t			v = (uintptr_t)p;
	char				buf[2 + sizeof(uintptr_t)*2];
	static const char	*hex = "0123456789abcdef";

	buf[0] = '0';
	buf[1] = 'x';
	for (size_t i = 0; i < sizeof(uintptr_t)*2; ++i) {
		size_t shift = (sizeof(uintptr_t)*2 - 1 - i) * 4;
		buf[2 + i] = hex[(v >> shift) & 0xF];
	}
	safe_write(buf, sizeof(buf));
}

void show_alloc_mem(void) {

	size_t		total = 0;
	t_type		types[3] = { TINY, SMALL, LARGE };
	const char	*hdr[3]  = { "TINY :\n", "SMALL:\n", "LARGE:\n" };
	int			ti;
	bool		printed;
	t_zone		*z;
	t_block		*b;
	char		*num;
	char		*t;

	if (!g_zones) {
		safe_write("Total : 0 bytes\n", ft_strlen("Total : 0 bytes\n"));
		return;
	}

	for (ti = 0; ti < 3; ++ti) {
		printed = false;
		for (z = g_zones; z; z = z->next) {
			if (z->type != types[ti])
				continue;
			if (!printed) {
				safe_write(hdr[ti], ft_strlen(hdr[ti]));
				printed = true;
			}
			// affiche debut de zone
			print_ptr(z->start);
			safe_write("\n", 1);

			// parcours les blocs
			for (b = z->blocks; b; b = b->next) {
				print_ptr(b->data);
				safe_write(" - ", 3);
				print_ptr((char*)b->data + b->size);
				safe_write(" : ", 3);

				num = ft_itoa(b->size);
				safe_write(num, ft_strlen(num));
				free(num);

				safe_write(" bytes\n", 7);
				total += b->size;
			}
		}
	}

	// affiche le total
	safe_write("Total : ", 8);
	{
		t = ft_itoa(total);
		safe_write(t, ft_strlen(t));
		free(t);
	}
	safe_write(" bytes\n", 7);
}
