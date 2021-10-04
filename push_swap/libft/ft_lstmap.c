/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:30 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:35:32 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear(t_list *lst, t_list *new, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	ft_lstclear(&new, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (tmp == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			clear(lst, new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
