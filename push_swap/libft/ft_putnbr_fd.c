/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:36:34 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:36:36 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			nb = -nb;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(nb, fd);
		}
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
		else
			ft_putchar_fd(nb + '0', fd);
	}
}
