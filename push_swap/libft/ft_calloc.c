/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:34:09 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:34:11 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
