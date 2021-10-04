/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:52:44 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 16:09:48 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freeStack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	while (temp->next != *stack)
	{
		free(temp);
		temp = temp->next;
	}
	free(temp);
	*stack = NULL;
}

static void	freeActions(t_actions **actions)
{
	t_actions	*temp;

	if (*actions == NULL)
		return ;
	temp = *actions;
	while (temp != NULL)
	{
		free(temp);
		temp = temp->next;
	}
	*actions = NULL;
}

void	freeAll(t_sortstate *state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	freeActions(actions);
	freeStack(a);
	freeStack(b);
	free(state);
}
