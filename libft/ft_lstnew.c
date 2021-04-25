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
