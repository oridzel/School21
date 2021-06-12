#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstring;
	size_t	len;
	size_t	s_len;

	if (!s1 || !set)
		return ((void *) 0);
	len = ft_strlen((char *)set);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen((char *)s1);
	while (s_len && ft_strchr(set, s1[s_len]))
		s_len--;
	trimstring = ft_substr((char *)s1, 0, s_len + 1);
	return (trimstring);
}
