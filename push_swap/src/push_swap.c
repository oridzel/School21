/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:11:01 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 17:32:00 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	threeSort(t_stack **stack, t_actions **actions)
{
	if ((*stack)->value < (*stack)->next->value && \
	(*stack)->value < (*stack)->previous->value)
	{
		if ((*stack)->next->value > (*stack)->previous->value)
		{
			swap(*stack, actions, 'a');
			rotate(stack, actions, 'a');
		}
	}
	else if ((*stack)->value > (*stack)->next->value && \
	(*stack)->value < (*stack)->previous->value)
		swap(*stack, actions, 'a');
	else if ((*stack)->value < (*stack)->next->value && \
	(*stack)->value > (*stack)->previous->value)
		reverse_rotate(stack, actions, 'a');
	else
	{
		if ((*stack)->next->value > (*stack)->previous->value)
		{
			swap(*stack, actions, 'a');
			reverse_rotate(stack, actions, 'a');
		}
		else
			rotate(stack, actions, 'a');
	}
}

static void	findPosition(t_sortstate *state, t_stack **a, t_stack **b, t_actions **actions)
{
	int	i;

	i = 0;
	while (i++ < state->size)
	{
		rotate(a, actions, 'a');
		if (*b && (*b)->value < (*a)->value)
			push(b, a, actions, 'a');
	}
}

static void	fiveSort(t_sortstate *state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;

	i = 0;
	while (i++ < state->size - 3)
		push(a, b, actions, 'b');
	threeSort(a, actions);
	i = 0;
	while (i++ < state->size - 3)
	{
		if ((*b)->value < (*a)->value)
			push(b, a, actions, 'a');
		else if ((*b)->value > (*a)->previous->value)
		{
			push(b, a, actions, 'a');
			rotate(a, actions, 'a');
		}
		else
			findPosition(state, a, b, actions);
	}
}

static void	fullSort(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;

	i = 0;
	while ((*state)->numSorted < (*state)->size)
	{
		(*state)->flag++;
		while ((*a)->value == (*state)->next)
			nextFound(state, a, actions);
		if (is_sorted(*a, (*state)->sortedArray, (*state)->size))
			return ;
		if ((*state)->numSorted > 0 && (*a)->sorted)
			while ((*a)->sorted || !((*a)->previous->sorted))
				reverse_rotate(a, actions, 'a');
		if (i % 2 == 0)
		{
			if (i > 0)
				(*state)->median = ((*state)->currentMax - (*state)->next) / 2
					+ (*state)->next;
			manipulateA(state, a, b, actions);
		}
		else
			manipulateB(state, a, b, actions);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stackA;
	t_stack		*stackB;
	t_sortstate	*state;
	t_actions	*actions;
	long		*arr;

	if (argc == 1 || argc == 2)
		exit(EXIT_FAILURE);
	stackA = NULL;
	state = NULL;
	arr = malloc(sizeof(long) * (argc - 1));
	if (arr)
		stackA = parse_input(argc, argv, arr);
	if (is_sorted(stackA, arr, argc - 1))
		exit(EXIT_SUCCESS);
	state = init_sortstate(&arr[0], argc);
	if (argc - 1 == 3)
		threeSort(&stackA, &actions);
	else if (argc - 1 <= 5)
		fiveSort(state, &stackA, &stackB, &actions);
	else
		fullSort(&state, &stackA, &stackB, &actions);
	printActions(actions);
	freeAll(state, &stackA, &stackB, &actions);
	return (0);
}
