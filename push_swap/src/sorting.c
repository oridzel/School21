/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:10:56 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 17:22:41 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sortstate	*init_sortstate(long *arr, int argc)
{
	t_sortstate	*state;

	state = malloc(sizeof(t_sortstate));
	if (state)
	{
		state->min = *arr;
		state->max = *(arr + argc - 2);
		state->currentMax = *(arr + argc - 2);
		state->sizeB = 0;
		state->numSorted = 0;
		state->size = argc - 1;
		state->next = *arr;
		state->flag = 0;
		state->median = state->max / 2 + state->min;
		state->sortedArray = arr;
	}
	return (state);
}

int	is_sorted(t_stack *stackA, long *arr, int size)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stackA;
	while (i < size)
	{
		if (*(arr + i) != temp->value)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

static void	startMerge(long **arr, t_index *ind)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ind->l;
	while (i < ind->sizeL && j < ind->sizeR)
	{
		if (*(ind->L + i) <= *(ind->R + j))
			*(*arr + k) = *(ind->L + i++);
		else
			*(*arr + k) = *(ind->R + j++);
		k++;
	}
	while (i < ind->sizeL)
	{
		*(*arr + k) = *(ind->L + i++);
		k++;
	}
	while (j < ind->sizeR)
	{
		*(*arr + k) = *(ind->R + j++);
		k++;
	}
}

static void	merge(long arr[], t_index *ind)
{
	int	i;

	i = -1;
	while (i++ < ind->sizeL)
		*(ind->L + i) = arr[ind->l + i];
	i = -1;
	while (i++ < ind->sizeR)
		*(ind->R + i) = arr[ind->m + 1 + i];
	startMerge(&arr, ind);
}

void	mergeSort(long arr[], t_index *start_ind)
{
	int		m;
	t_index	*ind;

	ind = malloc(sizeof(t_index));
	if (start_ind->l < start_ind->r && ind != NULL)
	{
		m = start_ind->l + (start_ind->r - start_ind->l) / 2;
		ind->l = start_ind->l;
		ind->r = m;
		mergeSort(arr, ind);
		ind->l = m + 1;
		ind->r = start_ind->r;
		mergeSort(arr, ind);
		ind->l = start_ind->l;
		ind->r = start_ind->r;
		ind->m = m;
		ind->sizeL = m - start_ind->l + 1;
		ind->sizeR = start_ind->r - m;
		ind->L = malloc(sizeof(long) * ind->sizeL);
		ind->R = malloc(sizeof(long) * ind->sizeR);
		merge(arr, ind);
		free(ind);
	}
}
