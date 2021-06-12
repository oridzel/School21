#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*src && size > 1)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
		size--;
	}
	*dest = '\0';
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
