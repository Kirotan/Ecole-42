#include "src/malloc.h"
#include <stdio.h>

int	main(){

	void	*ptr;

	ptr = malloc(8);
	if(ptr)
		printf("Allocation reussie 1: %p\n", ptr);
	else
		printf("Echec d'allocation.\n");


	ptr = malloc(0);
	if(ptr)
		printf("Allocation reussie 2: %p\n", ptr);
	else
		printf("Echec d'allocation.\n");



	ptr = malloc(80000);
	if(ptr)
		printf("Allocation reussie 3: %p\n", ptr);
	else
		printf("Echec d'allocation.\n");



	ptr = malloc(8.1);
	if(ptr)
		printf("Allocation reussie 4: %p\n", ptr);
	else
		printf("Echec d'allocation.\n");



	ptr = malloc(2);
	if(ptr)
		printf("Allocation reussie 5: %p\n", ptr);
	else
		printf("Echec d'allocation.\n");

	return (0);
}
