/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:22:32 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:45:59 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_found(t_sortstate **state, t_stack **a, t_actions **actions)
{
	(*a)->sorted = true;
	rotate(a, actions, 'a');
	(*state)->num_sorted++;
	(*state)->next = (*state)->sorted_array[(*state)->num_sorted];
}

static void	rotate_a(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	size_a;

	size_a = (*state)->size - (*state)->num_sorted;
	while (size_a > 0)
	{
		if ((*a)->value <= (*state)->median)
		{
			push(a, b, actions, 'b');
			(*state)->size_b++;
		}
		else
			rotate(a, actions, 'a');
		if ((*a)->value == (*state)->next && (*a)->previous->sorted)
		{
			while ((*a)->value == (*state)->next)
			{
				next_found(state, a, actions);
				size_a--;
			}
		}
		size_a--;
	}
}

void	manipulate_a(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	flag;

	if ((*a)->flag > 0)
	{
		flag = (*a)->flag;
		while ((*a)->flag == flag)
		{
			push(a, b, actions, 'b');
			(*state)->size_b++;
			if ((*a)->value == (*state)->next && (*a)->previous->sorted)
				next_found(state, a, actions);
		}
	}
	else
	{
		rotate_a(state, a, b, actions);
		if ((*a)->sorted && !(*a)->previous->sorted)
		{
			while ((*a)->sorted || !((*a)->previous->sorted))
				reverse_rotate(a, actions, 'a');
		}
	}
}
