#include "src/malloc.h"
#include <stdio.h>

int	main(){

	void	*ptr;

	ptr = malloc(8);
	if(ptr)
		printf("Allocation reussie 1: %p\n", ptr);
	else
		printf("Echec d'allocation1.\n");
	free(ptr);



	ptr = malloc(0);
	if(ptr)
		printf("Allocation reussie 2: %p\n", ptr);
	else
		printf("Echec d'allocation2.\n");
	free(ptr);



	ptr = malloc(80000);
	if(ptr)
		printf("Allocation reussie 3: %p\n", ptr);
	else
		printf("Echec d'allocation3.\n");
	free(ptr);



	ptr = malloc(900);
	if(ptr)
		printf("Allocation reussie 4: %p\n", ptr);
	else
		printf("Echec d'allocation4.\n");
	free(ptr);



	ptr = malloc(12345);
	if(ptr)
		printf("Allocation reussie 5: %p\n", ptr);
	else
		printf("Echec d'allocation5.\n");
	free(ptr);


	return (0);
}
