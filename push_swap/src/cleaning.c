/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:52:44 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:43:48 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **stack)
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

static void	free_actions(t_actions **actions)
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

void	free_all(t_sortstate *state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	free_actions(actions);
	free_stack(a);
	free_stack(b);
	free(state);
}
