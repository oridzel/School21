/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:05:30 by szeratul          #+#    #+#             */
/*   Updated: 2021/08/26 12:05:33 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	i = 0;
	needle_len = ft_strlen((char *) needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
					return ((char *) &haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
