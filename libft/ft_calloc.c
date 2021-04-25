#include "libft.h"

void	*ft_calloc(unsigned int count, size_t size)
{
	void	*array;

	if (size == 0 || count == 0)
		return (malloc(0));
	array = malloc(size * count);
	if (!array)
		return (NULL);
	ft_memset((unsigned char *)array, 0, size * count);
	return ((void *)array);
}
