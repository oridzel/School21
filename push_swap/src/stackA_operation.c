/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:22:32 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 14:02:43 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nextFound(t_sortstate **state, t_stack **a, t_actions **actions)
{
	(*a)->sorted = true;
	rotate(a, actions, 'a');
	(*state)->numSorted++;
	(*state)->next = (*state)->sortedArray[(*state)->numSorted];
}

static void	rotateA(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	sizeA;

	sizeA = (*state)->size - (*state)->numSorted;
	while (sizeA > 0)
	{
		if ((*a)->value <= (*state)->median)
		{
			push(a, b, actions, 'b');
			(*state)->sizeB++;
		}
		else
			rotate(a, actions, 'a');
		if ((*a)->value == (*state)->next && (*a)->previous->sorted)
		{
			while ((*a)->value == (*state)->next)
			{
				nextFound(state, a, actions);
				sizeA--;
			}
		}
		sizeA--;
	}
}

void	manipulateA(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	flag;

	if ((*a)->flag > 0)
	{
		flag = (*a)->flag;
		while ((*a)->flag == flag)
		{
			push(a, b, actions, 'b');
			(*state)->sizeB++;
			if ((*a)->value == (*state)->next && (*a)->previous->sorted)
				nextFound(state, a, actions);
		}
	}
	else
	{
		rotateA(state, a, b, actions);
		if ((*a)->sorted && !(*a)->previous->sorted)
		{
			while ((*a)->sorted || !((*a)->previous->sorted))
				reverse_rotate(a, actions, 'a');
		}
	}
}
