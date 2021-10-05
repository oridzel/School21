/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackB_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:02:21 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:47:13 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_found_in_b(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	while ((*state)->size_b > 0 && (*b)->value == (*state)->next)
	{
		push(b, a, actions, 'a');
		(*state)->size_b--;
		next_found(state, a, actions);
	}
	if ((*a)->value == (*state)->next)
		next_found(state, a, actions);
}

void	median_process(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	push(b, a, actions, 'a');
	(*a)->flag = (*state)->flag;
	if ((*a)->value == (*state)->next)
		next_found(state, a, actions);
}

void	push_from_b(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	push(b, a, actions, 'a');
	next_found(state, a, actions);
}

void	rotate_b(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < (*state)->size_b && n < (*state)->size_b)
	{
		if ((*b)->value >= (*state)->median)
		{
			n++;
			median_process(state, a, b, actions);
		}
		else
			rotate(b, actions, 'b');
		if (n < (*state)->size_b && (*b)->value == (*state)->next && \
		((*a)->previous->sorted || (*state)->num_sorted == 0))
		{
			while (n < (*state)->size_b && (*b)->value == (*state)->next)
			{
				n++;
				push_from_b(state, a, b, actions);
			}
		}
	}
	(*state)->size_b -= n;
}

void	manipulate_b(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	while ((*state)->size_b > 0)
	{
		(*state)->current_max = (*state)->median;
		(*state)->median = ((*state)->current_max - (*state)->next) / 2
			+ (*state)->next;
		if ((*b)->value == (*state)->next && \
		((*a)->previous->sorted || (*state)->num_sorted == 0))
			process_found_in_b(state, a, b, actions);
		rotate_b(state, a, b, actions);
		(*state)->flag++;
	}
	(*state)->current_max = (*state)->max;
}
