/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:09:19 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/05 08:45:02 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_numeric_input(char *str)
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

static int	duplicate_check(int arr[], int value, int index)
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

static int	check_input(char *str, int arr[], int index)
{
	return (is_not_numeric_input(str) || \
	duplicate_check(arr, ft_atoi(str), index - 1) || \
	ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN);
}

t_stack	*parse_input(int argc, char **argv, int arr[])
{
	int		i;
	t_stack	*a;
	t_index	*ind;

	ind = malloc(sizeof(t_index));
	i = 0;
	a = NULL;
	if (argc > 2)
	{
		while (++i < argc)
		{
			if (check_input(argv[i], arr, i))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			arr[i - 1] = ft_atoi(argv[i]);
			insert(&a, arr[i - 1], false);
		}
		ind->l = 0;
		ind->r = argc - 2;
		merge_sort(arr, ind);
		free(ind);
	}
	return (a);
}
