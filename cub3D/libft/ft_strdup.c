#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!source)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!new)
		return (NULL);
	while (*source)
		new[i++] = *source++;
	new[i] = '\0';
	return (new);
}
