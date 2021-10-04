/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:37:42 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:37:43 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
