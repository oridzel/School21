/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:11:01 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:47:58 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack **stack, t_actions **actions)
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

static void	find_min_max(t_sortstate *state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if ((*a)->value == *(state->sorted_array))
		{
			push(a, b, actions, 'b');
			i++;
		}
		else if ((*a)->value == *(state->sorted_array + state->size - 1))
		{
			push(a, b, actions, 'b');
			i++;
		}
		else
			rotate(a, actions, 'a');
		if (state->size == 4 && i == 1)
			break ;
	}
}

static void	five_sort(t_sortstate *state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;

	i = 0;
	if (state->size == 2)
	{
		swap(*a, actions, 'a');
		return ;
	}
	find_min_max(state, a, b, actions);
	three_sort(a, actions);
	while (i++ < state->size - 3)
	{
		push(b, a, actions, 'a');
		if ((*a)->value > (*a)->previous->value)
			rotate(a, actions, 'a');
	}
}

static void	full_sort(t_sortstate **state, t_stack **a, t_stack **b,
		t_actions **actions)
{
	int	i;

	i = 0;
	while ((*state)->num_sorted < (*state)->size)
	{
		(*state)->flag++;
		while ((*a)->value == (*state)->next)
			next_found(state, a, actions);
		if (is_sorted(*a, (*state)->sorted_array, (*state)->size))
			return ;
		if ((*state)->num_sorted > 0 && (*a)->sorted)
			while ((*a)->sorted || !((*a)->previous->sorted))
				reverse_rotate(a, actions, 'a');
		if (i % 2 == 0)
		{
			if (i > 0)
				(*state)->median = ((*state)->current_max - (*state)->next) / 2
					+ (*state)->next;
			manipulate_a(state, a, b, actions);
		}
		else
			manipulate_b(state, a, b, actions);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_sortstate	*state;
	t_actions	*actions;
	int			*arr;

	if (argc == 1 || argc == 2)
		exit(EXIT_FAILURE);
	a = NULL;
	state = NULL;
	arr = malloc(sizeof(int) * (argc - 1));
	if (arr)
		a = parse_input(argc, argv, arr);
	if (is_sorted(a, arr, argc - 1))
		exit(EXIT_SUCCESS);
	state = init_sortstate(&arr[0], argc);
	if (argc - 1 == 3)
		three_sort(&a, &actions);
	else if (argc - 1 <= 5)
		five_sort(state, &a, &b, &actions);
	else
		full_sort(&state, &a, &b, &actions);
	print_actions(actions);
	free_all(state, &a, &b, &actions);
	return (0);
}
