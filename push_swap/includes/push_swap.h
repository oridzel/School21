/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:44:12 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 17:25:06 by szeratul         ###   ########.fr       */
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
	long			value;
	struct s_stack	*previous;
	struct s_stack	*next;
	int				flag;
	bool			sorted : 1;
}	t_stack;

typedef struct s_sortstate
{
	long	min;
	long	max;
	long	currentMax;
	long	median;
	int		sizeB;
	int		size;
	long	next;
	int		flag;
	int		numSorted;
	long	*sortedArray;
}	t_sortstate;

typedef struct s_actions
{
	char				*action;
	struct s_actions	*next;
}	t_actions;

typedef struct s_index
{
	int		l;
	int		r;
	int		m;
	int		sizeL;
	int		sizeR;
	long	*L;
	long	*R;
}	t_index;

t_stack		*initStack(long value);
t_sortstate	*init_sortstate(long *arr, int argc);
void		insert(t_stack **stack, long value, bool push_front);
void		swap(t_stack *stack, t_actions **actions, char whichStack);
void		rotate(t_stack **stack, t_actions **actions, char whichStack);
void		reverse_rotate(t_stack **stack, t_actions **actions,
				char whichStack);
void		r_reverse_rotate(t_stack **a, t_stack **b, t_actions **actions);
void		push(t_stack **stackA, t_stack **stackB, t_actions **actions,
				char whichStack);
void		pop(t_stack **stack);
void		nextFound(t_sortstate **state, t_stack **a, t_actions **actions);
void		manipulateA(t_sortstate **state, t_stack **a, t_stack **b,
				t_actions **actions);
void		manipulateB(t_sortstate **state, t_stack **a, t_stack **b,
				t_actions **actions);
void		mergeSort(long arr[], t_index *ind);
int			is_sorted(t_stack *stackA, long *arr, int size);
void		add_action_back(t_actions **lst, char *action);
void		printActions(t_actions *actions);
void		freeAll(t_sortstate *state, t_stack **a, t_stack **b,
				t_actions **actions);
t_stack		*parse_input(int argc, char **argv, long arr[]);

#endif