/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:47:13 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 19:09:39 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, t_actions **actions, char which_stack)
{
	long	temp;

	if (stack != NULL)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
	}
	if (which_stack == 'a')
		add_action_back(actions, "sa");
	else if (which_stack == 'b')
		add_action_back(actions, "sb");
}

void	rotate(t_stack **stack, t_actions **actions, char which_stack)
{
	if (*stack != NULL)
		*stack = (*stack)->next;
	if (which_stack == 'a')
		add_action_back(actions, "ra");
	else if (which_stack == 'b')
		add_action_back(actions, "rb");
}

void	reverse_rotate(t_stack **stack, t_actions **actions, char which_stack)
{
	if (*stack != NULL)
		*stack = (*stack)->previous;
	if (which_stack == 'a')
		add_action_back(actions, "rra");
	else if (which_stack == 'b')
		add_action_back(actions, "rrb");
}

void	push(t_stack **a, t_stack **b, t_actions **actions, char which_stack)
{
	if (*a == NULL)
		return ;
	insert(b, (*a)->value, true);
	pop(a);
	if (which_stack == 'a')
		add_action_back(actions, "pa");
	else if (which_stack == 'b')
		add_action_back(actions, "pb");
}

void	pop(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next == *stack)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp = (*stack)->next;
		temp->previous = (*stack)->previous;
		(*stack)->previous->next = temp;
		free(*stack);
		*stack = temp;
	}
}
