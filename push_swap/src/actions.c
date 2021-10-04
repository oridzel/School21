/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:52:45 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 12:53:26 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_actions	*create_new_action(char *str)
{
	t_actions	*temp;

	temp = malloc(sizeof(t_actions));
	if (temp)
	{
		temp->action = str;
		temp->next = NULL;
	}
	return (temp);
}

void	add_action_back(t_actions **lst, char *action)
{
	t_actions	*tmp;

	if (*lst == NULL)
	{
		*lst = create_new_action(action);
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_new_action(action);
}

void	printActions(t_actions *actions)
{
	t_actions	*temp;
	int			count;

	temp = actions;
	count = 0;
	while (temp != NULL)
	{
		ft_putstr_fd(temp->action, 1);
		ft_putchar_fd('\n', 1);
		temp = temp->next;
		count++;
	}
}

t_stack	*createNewElement(long value)
{
	t_stack	*newElement;

	newElement = malloc(sizeof(t_stack));
	if (newElement != NULL)
	{
		newElement->next = newElement;
		newElement->previous = newElement;
		newElement->value = value;
		newElement->flag = 0;
		newElement->sorted = false;
	}
	return (newElement);
}

void	insert(t_stack **stack, long value, bool push_front)
{
	t_stack	*new;
	t_stack	*last;

	new = createNewElement(value);
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = (*stack)->previous;
	new->next = (*stack);
	new->previous = last;
	last->next = new;
	(*stack)->previous = new;
	if (push_front)
		*stack = new;
}
