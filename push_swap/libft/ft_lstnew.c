/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:36 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:35:37 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;
	t_list	*n;

	list = NULL;
	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (0);
	n->content = content;
	n->next = NULL;
	list = n;
	return (list);
}
