#include "ft_processor.h"
#include <stdio.h>

void	ft_putstr(char *s, int length, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < length)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

char	*ft_process_itoa(unsigned long long nb, unsigned char base, int capital)
{
	int		number_length;
	char	*str;

	number_length = ft_calculate_number_length(nb, base);
	str = malloc(number_length + 1);
	if (str)
	{
		str[number_length] = '\0';
		while (number_length > 0)
		{
			str[number_length - 1] = nb % base;
			if (nb % base > 9)
			{
				if (capital == 0)
					str[number_length - 1] += 'a' - 10;
				else
					str[number_length - 1] += 'A' - 10;
			}
			else
				str[number_length - 1] += '0';
			nb /= base;
			number_length--;
		}
	}
	return (str);
}

int	ft_calculate_number_length(unsigned long long n, unsigned char base)
{
	int	length;

	length = 0;
	if (n == 0)
		length++;
	else
	{
		while (n > 0)
		{
			n /= base;
			length++;
		}
	}
	return (length);
}

t_number	*ft_init_number(long long nb, unsigned char base)
{
	t_number	*number;

	number = (t_number *)malloc(sizeof(t_number));
	if (number)
	{
		number->value = (unsigned long long)nb;
		number->base = base;
		number->sign = '+';
		if (nb < 0)
		{
			number->sign = '-';
			number->value = -((unsigned long long)nb);
		}	
	}
	return (number);
}

void	ft_processor(t_format *format, va_list args)
{
	if (format->type == 'd' || format->type == 'i')
		format->printed_length += ft_process_d(format,
				(long long)va_arg(args, int), 10U, 0);
	else if (format->type == 's')
		format->printed_length += ft_process_str(format, va_arg(args, char *));
	else if (format->type == 'c')
		format->printed_length += ft_process_chr(format, va_arg(args, int));
	else if (format->type == 'u')
		format->printed_length += ft_process_d(format,
				va_arg(args, unsigned int), 10U, 0);
	else if (format->type == 'x')
		format->printed_length += ft_process_d(format,
				va_arg(args, unsigned int), 16U, 0);
	else if (format->type == 'X')
		format->printed_length += ft_process_d(format,
				va_arg(args, unsigned int), 16U, 1);
	else if (format->type == 'p')
		format->printed_length += ft_process_ptr(format,
				(unsigned long long)va_arg(args, void *), 0);
	else if (format->type == '%')
		format->printed_length += ft_process_chr(format, '%');
}
