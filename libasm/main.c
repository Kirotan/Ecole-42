#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

extern long	ft_strlen(const char *str);
extern char	*ft_strcpy(char *dest, const char *src);
extern int	ft_strcmp(char *src_A, const char *src_B);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char	*ft_strdup(const char *s);


int main(){

	const char	*txt = "Assembleur 64 bits";
	char	dest[ft_strlen(txt)];


	printf("######### FT_STRLEN #########\n");
	printf("Longueur mon ft_strlen: %ld\n", ft_strlen(txt));
	printf("Longueur vrai strlen: %ld\n\n\n", strlen(txt));


	printf("######### FT_STRCPY #########\n");
	ft_strcpy(dest, txt);
	printf("Texte source : %s\n", txt);
	printf("Texte destination mon ft_strcpy : %s\n",dest);
	printf("Texte destination vrai strcpy : %s\n\n\n",dest);


	printf("######### FT_STRCMP #########\n");
	char	*src_A = "Hello";
	char	*src_B = "Hello";
	char	*src_C = "Hellp";
	printf("Source A : %s\n", src_A);
	printf("Source B : %s\n", src_B);
	printf("Source C : %s\n\n", src_C);
	printf("Comparaison mon ft_strcmp A et B : %d\n", ft_strcmp(src_A, src_B));
	printf("Comparaison vrai strcmp A et B : %d\n\n", strcmp(src_A, src_B));
	printf("Comparaison mon ft_strcmp A et C : %d\n", ft_strcmp(src_A, src_C));
	printf("Comparaison vrai strcmp A et C : %d\n\n", strcmp(src_A, src_C));
	printf("Comparaison mon ft_strcmp C et A : %d\n", ft_strcmp(src_C, src_A));
	printf("Comparaison vrai strcmp C et A : %d\n\n\n", strcmp(src_C, src_A));


	printf("######### FT_WRITE #########\n");
	int	ret_write = ft_write(-1, "Test de mon ft_write en Assembleur.\n", 37);
	if (ret_write == -1){
		printf("Erreur write: ret = %d, errno = %d (%s)\n",ret_write, errno, strerror(errno));
	}
	ret_write = write(-1, "Le vrai write.\n\n\n", 18);
	if (ret_write == -1){
		printf("Erreur write: ret = %d, errno = %d (%s)\n",ret_write, errno, strerror(errno));
	}


	printf("######### FT_READ #########\n");
	char buffer[100];
	ssize_t ret = ft_read(0, buffer, 100);
	buffer[ret] = '\0';
	if (ret == -1) {
		printf("Erreur read: ft_read retourne -1.\n");
		printf("errno = %d\n", errno); // Affiche la valeur errno
	}
	printf("Texte lu par mon ft_read: %s\n", buffer);
	ssize_t ret_bis = read(0, buffer, 100);
	buffer[ret_bis] = '\0';
	if (ret_bis == -1) {
		printf("Erreur : ft_read retourne -1.\n");
		printf("errno = %d\n", errno); // Affiche la valeur errno
	}
	printf("Texte lu par le vrai read: %s\n\n", buffer);


	printf("######### FT_STRDUP #########\n");
	char *src_D = "The cake is a lie.";
	char *copy = ft_strdup(src_D);
	printf("Original: %s\n", src_D);
	printf("Mon ft_strdup: %s\n", copy);
	if (copy == NULL) {
		printf("Erreur : ft_strdup a echoue (malloc a retourne NULL)\n");
		return 1;
	} else {
		free(copy);
	}
	copy = strdup(src_D);
	printf("Le vrai strdup: %s\n", copy);
	free(copy);

	return 0;
}
