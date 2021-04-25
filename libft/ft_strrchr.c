#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		len;

	ch = c;
	i = 0;
	len = ft_strlen((char *) s);
	if ((char) c == '\0')
		return ((char *)s + len);
	while (i < len)
	{
		if (*(s + len - i - 1) == ch)
			return ((char *)(s + len - i - 1));
		i++;
	}
	return (0);
}
