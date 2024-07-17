#include "libft.h"

int	ft_isdigit(int charac)
{
	if (charac < '0' || charac > '9')
	{
		return (0);
	}
	return (1);
}
