/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:44:12 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:40:47 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
	int				flag;
	bool			sorted : 1;
}	t_stack;

typedef struct s_sortstate
{
	int	min;
	int	max;
	int	current_max;
	int	median;
	int	size_b;
	int	size;
	int	next;
	int	flag;
	int	num_sorted;
	int	*sorted_array;
}	t_sortstate;

typedef struct s_actions
{
	char				*action;
	struct s_actions	*next;
}	t_actions;

typedef struct s_index
{
	int	l;
	int	r;
	int	m;
	int	size_l;
	int	size_r;
	int	*left_array;
	int	*right_array;
}	t_index;

t_stack		*init_stack(int value);
t_sortstate	*init_sortstate(int *arr, int argc);
void		insert(t_stack **stack, int value, bool push_front);
void		swap(t_stack *stack, t_actions **actions, char which_stack);
void		rotate(t_stack **stack, t_actions **actions, char which_stack);
void		reverse_rotate(t_stack **stack, t_actions **actions,
				char which_stack);
void		r_reverse_rotate(t_stack **a, t_stack **b, t_actions **actions);
void		push(t_stack **a, t_stack **b, t_actions **actions,
				char which_stack);
void		pop(t_stack **stack);
void		next_found(t_sortstate **state, t_stack **a, t_actions **actions);
void		manipulate_a(t_sortstate **state, t_stack **a, t_stack **b,
				t_actions **actions);
void		manipulate_b(t_sortstate **state, t_stack **a, t_stack **b,
				t_actions **actions);
void		merge_sort(int arr[], t_index *ind);
int			is_sorted(t_stack *a, int *arr, int size);
void		add_action_back(t_actions **lst, char *action);
void		print_actions(t_actions *actions);
void		free_all(t_sortstate *state, t_stack **a, t_stack **b,
				t_actions **actions);
t_stack		*parse_input(int argc, char **argv, int arr[]);

#endif