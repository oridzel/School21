/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:10:56 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:45:26 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sortstate	*init_sortstate(int *arr, int argc)
{
	t_sortstate	*state;

	state = malloc(sizeof(t_sortstate));
	if (state)
	{
		state->min = *arr;
		state->max = *(arr + argc - 2);
		state->current_max = *(arr + argc - 2);
		state->size_b = 0;
		state->num_sorted = 0;
		state->size = argc - 1;
		state->next = *arr;
		state->flag = 0;
		state->median = state->max / 2 + state->min;
		state->sorted_array = arr;
	}
	return (state);
}

int	is_sorted(t_stack *a, int *arr, int size)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = a;
	while (i < size)
	{
		if (*(arr + i) != temp->value)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

static void	start_merge(int **arr, t_index *ind)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ind->l;
	while (i < ind->size_l && j < ind->size_r)
	{
		if (*(ind->left_array + i) <= *(ind->right_array + j))
			*(*arr + k) = *(ind->left_array + i++);
		else
			*(*arr + k) = *(ind->right_array + j++);
		k++;
	}
	while (i < ind->size_l)
	{
		*(*arr + k) = *(ind->left_array + i++);
		k++;
	}
	while (j < ind->size_r)
	{
		*(*arr + k) = *(ind->right_array + j++);
		k++;
	}
}

static void	merge(int arr[], t_index *ind)
{
	int	i;

	i = -1;
	while (i++ < ind->size_l)
		*(ind->left_array + i) = arr[ind->l + i];
	i = -1;
	while (i++ < ind->size_r)
		*(ind->right_array + i) = arr[ind->m + 1 + i];
	start_merge(&arr, ind);
}

void	merge_sort(int arr[], t_index *start_ind)
{
	int		m;
	t_index	*ind;

	ind = malloc(sizeof(t_index));
	if (start_ind->l < start_ind->r && ind != NULL)
	{
		m = start_ind->l + (start_ind->r - start_ind->l) / 2;
		ind->l = start_ind->l;
		ind->r = m;
		merge_sort(arr, ind);
		ind->l = m + 1;
		ind->r = start_ind->r;
		merge_sort(arr, ind);
		ind->l = start_ind->l;
		ind->r = start_ind->r;
		ind->m = m;
		ind->size_l = m - start_ind->l + 1;
		ind->size_r = start_ind->r - m;
		ind->left_array = malloc(sizeof(int) * ind->size_l);
		ind->right_array = malloc(sizeof(int) * ind->size_r);
		merge(arr, ind);
		free(ind);
	}
}
