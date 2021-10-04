/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:54:21 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:40:35 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printArray(long A[], int size)
{
	int	i;

	printf("Sorted array:\n");
	i = 0;
	while (i < size)
		printf("%ld ", A[i]);
	printf("\n");
}

void	printStack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = (*stack);
	while (temp->next != *stack)
	{
		printf("%d\t%li\t%i\n", temp->flag, temp->value, temp->sorted);
		temp = temp->next;
	}
	printf("%d\t%li\t%i\n", temp->flag, temp->value, temp->sorted);
}
