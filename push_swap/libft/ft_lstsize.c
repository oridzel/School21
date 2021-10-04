/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:44 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:35:46 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		size;

	if (lst == NULL)
		return (0);
	tmp = lst;
	size = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size + 1);
}
