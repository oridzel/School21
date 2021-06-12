#include <stdio.h>
#include "ft_parser.h"
#include "ft_processor.h"

static t_format	*init_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (format == NULL)
		return (0);
	format->minus = 0;
	format->zero = 0;
	format->width = 0;
	format->precision = 0;
	format->dot = 0;
	format->type = '\0';
	format->printed_length = 0;
	format->space = 0;
	format->plus = 0;
	return (format);
}

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_parser(char *stream, va_list args)
{
	t_format	*format;
	int			i;
	int			total_length;

	i = 0;
	total_length = 0;
	while (stream[i] != '\0')
	{	
		if (stream[i] == '%')
		{
			format = init_format();
			if (!format)
				return (-1);
			i = ft_parse_format(stream, format, args, i + 1);
			if (stream[i])
				i++;
			ft_processor(format, args);
			total_length += format->printed_length;
			free(format);
		}
		else
		{
			ft_putchar_fd(stream[i], 1);
			total_length++;
			i++;
		}
	}
	return (total_length);
}
