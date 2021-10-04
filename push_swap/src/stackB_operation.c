/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackB_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:02:21 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 14:40:50 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	processFoundInB(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	while ((*state)->sizeB > 0 && (*b)->value == (*state)->next)
	{
		push(b, a, actions, 'a');
		(*state)->sizeB--;
		nextFound(state, a, actions);
	}
	if ((*a)->value == (*state)->next)
		nextFound(state, a, actions);
}

void	medianProcess(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	push(b, a, actions, 'a');
	(*a)->flag = (*state)->flag;
	if ((*a)->value == (*state)->next)
		nextFound(state, a, actions);
}

void	pushFromB(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	push(b, a, actions, 'a');
	nextFound(state, a, actions);
}

void	rotateB(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < (*state)->sizeB && n < (*state)->sizeB)
	{
		if ((*b)->value >= (*state)->median)
		{
			n++;
			medianProcess(state, a, b, actions);
		}
		else
			rotate(b, actions, 'b');
		if (n < (*state)->sizeB && (*b)->value == (*state)->next && \
		((*a)->previous->sorted || (*state)->numSorted == 0))
		{
			while (n < (*state)->sizeB && (*b)->value == (*state)->next)
			{
				n++;
				pushFromB(state, a, b, actions);
			}
		}
	}
	(*state)->sizeB -= n;
}

void	manipulateB(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	while ((*state)->sizeB > 0)
	{
		(*state)->currentMax = (*state)->median;
		(*state)->median = ((*state)->currentMax - (*state)->next) / 2
			+ (*state)->next;
		if ((*b)->value == (*state)->next && \
		((*a)->previous->sorted || (*state)->numSorted == 0))
			processFoundInB(state, a, b, actions);
		rotateB(state, a, b, actions);
		(*state)->flag++;
	}
	(*state)->currentMax = (*state)->max;
}
