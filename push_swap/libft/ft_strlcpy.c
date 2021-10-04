/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:37:13 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:37:14 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
