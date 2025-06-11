#include "src/malloc.h"
#include <stdio.h>

int	main(){

	// void	*ptr_one;
	// char	*ptr;
	// char	*new_ptr;

	// ptr_one = malloc(8);
	// if(ptr_one)
	// 	printf("Allocation reussie 1: %p\n", ptr_one);
	// else
	// 	printf("Echec d'allocation1.\n");
	// free(ptr_one);



	// ptr_one = malloc(0);
	// if(ptr_one)
	// 	printf("Allocation reussie 2: %p\n", ptr_one);
	// else
	// 	printf("Echec d'allocation2.\n");
	// free(ptr_one);



	// ptr_one = malloc(80000);
	// if(ptr_one)
	// 	printf("Allocation reussie 3: %p\n", ptr_one);
	// else
	// 	printf("Echec d'allocation3.\n");
	// free(ptr_one);



	// ptr_one = malloc(900);
	// if(ptr_one)
	// 	printf("Allocation reussie 4: %p\n", ptr_one);
	// else
	// 	printf("Echec d'allocation4.\n");
	// free(ptr_one);



	// ptr_one = malloc(12345);
	// if(ptr_one)
	// 	printf("Allocation reussie 5: %p\n", ptr_one);
	// else
	// 	printf("Echec d'allocation5.\n\n\n");
	// free(ptr_one);



	// printf("=== Test realloc ===\n\n");

	// // 1) realloc(NULL, size) doit se comporter comme malloc(size)
	// printf("1) realloc(NULL, 16) → malloc(16)\n");
	// ptr = realloc(NULL, 16);
	// if (ptr) {
	// 	ft_strlcpy(ptr, "Hello, realloc!", 16);
	// 	printf("   Contenu après alloc : \"%s\" (addr=%p)\n", ptr, (void *)ptr);
	// } else {
	// 	printf("   Échec realloc(NULL, 16)\n");
	// }

	// // 2) Agrandir le bloc existant (TINY) de 16 → 64 octets
	// printf("\n2) realloc(ptr, 64) : on agrandit un bloc TINY en place si possible\n");
	// new_ptr = realloc(ptr, 64);
	// if (new_ptr) {
	// 	printf("   Adresse avant : %p, après : %p\n", (void *)ptr, (void *)new_ptr);
	// 	printf("   Contenu préservé : \"%s\"\n", new_ptr);
	// 	// On peut ajouter du texte dans la zone élargie
	// 	ft_strlcat(new_ptr, " + plus d'espace", 33);
	// 	printf("   Contenu modifié : \"%s\"\n", new_ptr);
	// } else {
	// 	printf("   Échec realloc(ptr, 64)\n");
	// }
	// ptr = new_ptr;

	// // 3) Réduire la taille du bloc (64 → 32 octets)
	// printf("\n3) realloc(ptr, 32) : on rétrécit le bloc\n");
	// new_ptr = realloc(ptr, 32);
	// if (new_ptr) {
	// 	printf("   Adresse avant : %p, après : %p\n", (void *)ptr, (void *)new_ptr);
	// 	printf("   Contenu préservé (tronqué à 32 octets max) : \"%.*s\"\n", 31, new_ptr);
	// } else {
	// 	printf("   Échec realloc(ptr, 32)\n");
	// }
	// ptr = new_ptr;

	// // 4) realloc(ptr, 0) : doit libérer ptr et retourner NULL
	// printf("\n4) realloc(ptr, 0) : libère le bloc et retourne NULL\n");
	// new_ptr = realloc(ptr, 0);
	// if (new_ptr == NULL) {
	// 	printf("   realloc(ptr, 0) a libéré le bloc et retourné NULL\n");
	// } else {
	// 	printf("   Problème : realloc(ptr, 0) n'a pas retourné NULL\n");
	// }
	// free(ptr);
	// free(new_ptr);

	// // 5) realloc un bloc LARGE
	// printf("\n5) Test avec un bloc LARGE (par ex. > SMALL_MAX)\n");
	// size_t large_size = SMALL_MAX + 1024; // taille juste au-dessus de SMALL_MAX
	// ptr = malloc(large_size);
	// if (ptr) {
	// 	ft_memset(ptr, 'A', large_size);
	// 	printf("   malloc(%zu) LARGE → addr=%p\n", large_size, (void *)ptr);

	// 	// agrandir au-delà de la zone LARGE actuelle
	// 	size_t larger_size = large_size + 2048;
	// 	new_ptr = realloc(ptr, larger_size);
	// 	if (new_ptr) {
	// 		printf("   realloc(ptr, %zu) : addr avant=%p, après=%p\n",
	// 			larger_size, (void *)ptr, (void *)new_ptr);
	// 		// vérifier que le contenu initial est préservé
	// 		printf("   [vérification contenu] premier octet : '%c'\n", new_ptr[0]);
	// 	} else {
	// 		printf("   Échec realloc(ptr, %zu)\n", larger_size);
	// 	}
	// 	ptr = new_ptr;

	// 	// réduire le bloc LARGE (-> reste LARGE)
	// 	size_t smaller_size = large_size / 2;
	// 	new_ptr = realloc(ptr, smaller_size);
	// 	if (new_ptr) {
	// 		printf("   realloc(ptr, %zu) (réduction) : addr avant=%p, après=%p\n",
	// 			smaller_size, (void *)ptr, (void *)new_ptr);
	// 	} else {
	// 		printf("   Échec realloc(ptr, %zu)\n", smaller_size);
	// 	}
	// 	ptr = new_ptr;

	// 	free(ptr);
	// } else {
	// 	printf("   Échec malloc(%zu) pour le test LARGE\n", large_size);
	// }

	// // 6) realloc d’un pointeur non valide (pas alloué par notre malloc)
	// printf("\n6) realloc(pointeurrandom, 16) : pointeur non alloué\n");
	// char stack_buf[16];
	// new_ptr = realloc(stack_buf, 16);
	// if (new_ptr == NULL) {
	// 	printf("   Bon comportement : realloc d’un pointeur invalide retourne NULL\n");
	// } else {
	// 	printf("   Problème : realloc d’un pointeur invalide a renvoyé %p\n", (void *)new_ptr);
	// 	free(new_ptr);
	// }

	// printf("\n=== Fin des tests realloc ===\n");


	char *p1 = malloc(32);
	char *p2 = malloc(1000);
	char *p3 = malloc(50000);
	char *p4 = malloc(50000);

	show_alloc_mem();

	free(p1);
	free(p2);
	free(p3);
	free(p4);

	return (0);
}
