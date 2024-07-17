#include "libft.h"

char	*ft_strchr(const char *string, int searched_char)
{
	if (!string)
		return (NULL);
	while (*string != '\0')
	{
		if (*string == (char)searched_char)
			return ((char *)string);
		string++;
	}
	if ((char)searched_char == '\0')
		return ((char *)string);
	return (NULL);
}
