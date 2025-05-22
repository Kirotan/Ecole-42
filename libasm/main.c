#include <stdio.h>
#include <string.h>

extern long ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int	ft_strcmp(char *src_A, const char *src_B);

int main(){

	const char	*txt = "Assembleur 64 bits";
	char	dest[ft_strlen(txt)];


	printf("###### FT_STRLEN ######\n");
	printf("Longueur mon ft_strlen: %ld\n", ft_strlen(txt));
	printf("Longueur vrai strlen: %ld\n\n", strlen(txt));


	printf("###### FT_STRCPY ######\n");
	ft_strcpy(dest, txt);
	printf("Texte source : %s\n", txt);
	printf("Texte destination mon ft_strcpy : %s\n",dest);
	printf("Texte destination vrai strcpy : %s\n\n",dest);

	printf("###### FT_STRCMP ######\n");
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
	printf("Comparaison vrai strcmp C et A : %d\n\n", strcmp(src_C, src_A));

	return 0;
}
