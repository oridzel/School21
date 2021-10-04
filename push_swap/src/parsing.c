/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:09:19 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 13:03:37 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isNotNumericInput(char *str)
{
	int	c;

	c = 0;
	if (str[c] == '-')
		c++;
	while (str[c])
	{
		if (!ft_isdigit(str[c]))
			return (1);
		c++;
	}
	return (0);
}

static int	duplicateCheck(long arr[], long value, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	checkInput(char *str, long arr[], int index)
{
	return (isNotNumericInput(str) || duplicateCheck(arr,
			ft_atoi(str), index - 1) || ft_atoi(str) > INT_MAX);
}

t_stack	*parse_input(int argc, char **argv, long arr[])
{
	int		i;
	t_stack	*stackA;
	t_index	*ind;

	ind = malloc(sizeof(t_index));
	i = 0;
	stackA = NULL;
	if (argc > 2)
	{
		while (++i < argc)
		{
			if (checkInput(argv[i], arr, i))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			arr[i - 1] = ft_atoi(argv[i]);
			insert(&stackA, (long)arr[i - 1], false);
		}
		ind->l = 0;
		ind->r = argc - 2;
		mergeSort(arr, ind);
		free(ind);
	}
	return (stackA);
}
