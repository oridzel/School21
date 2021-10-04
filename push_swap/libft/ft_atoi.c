/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:33:49 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:38:37 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(char *str)
{
	unsigned long long	nb;
	int					sign;
	unsigned int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+' || str[i] == '0')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		nb = nb * 10 + (str[i++] - '0');
	if (nb >= 9223372036854775808ULL)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (sign * nb);
}
