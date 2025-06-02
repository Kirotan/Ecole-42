#include "./src/malloc_structs.h"
#include <stdio.h>

int	main(){

	void	*ptr;

	ptr = malloc(8);
	if(ptr)
		printf("Allocation reussie : %p\n", ptr);
	else
		printf("Echec d'allocation.\n");

}
