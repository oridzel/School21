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
