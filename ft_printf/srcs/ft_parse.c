#include "ft_parser.h"

int	ft_parse_minus(char *stream, t_format *format, va_list args, int i)
{
	i++;
	if (format->minus)
	{
		while (stream[i] == '-' || stream[i] == '0')
			i++;
		return (i);
	}
	format->minus = true;
	format->zero = false;
	while (stream[i] == '-' || stream[i] == '0')
		i++;
	i = ft_parse_width(stream, format, args, i);
	return (i);
}

int	ft_parse_width(char *stream, t_format *format, va_list args, int i)
{
	int	nb;

	nb = 0;
	if (ft_isdigit(stream[i]))
	{
		nb = ft_atoi(&stream[i]);
		i += ft_numlen(nb);
	}
	format->width = nb;
	if (stream[i] == '.')
		i = ft_parse_precision(stream, format, args, i);
	return (i);
}

int	ft_parse_precision(char *stream, t_format *format, va_list args, int i)
{
	int	nb;

	nb = 0;
	i++;
	format->dot = true;
	if (ft_isalpha(stream[i]) || stream[i] == '%')
		ft_check_precision(format);
	while (stream[i] == '0' || (stream[i] == '-' || stream[i] == '.'))
	{
		i++;
		ft_check_precision(format);
	}
	if (ft_isdigit(stream[i]))
	{
		nb = ft_atoi(&stream[i]);
		i += ft_numlen(nb);
		format->precision = nb;
		ft_check_precision(format);
	}
	if (stream[i] == '*')
		i = ft_parse_star(stream, format, args, i);
	while (stream[i] == '*')
		i++;
	return (i);
}

int	ft_parse_star(char *stream, t_format *format, va_list args, int i)
{
	i++;
	if (!format->dot)
	{
		format->width = va_arg(args, int);
		if (format->width < 0)
		{
			format->minus = true;
			format->zero = false;
			format->width = -format->width;
		}
	}
	else
	{
		format->precision = va_arg(args, int);
		ft_check_precision(format);
	}
	if (stream[i] == '.')
		i = ft_parse_precision(stream, format, args, i);
	if (stream[i] == '*')
		i = ft_parse_star(stream, format, args, i);
	while (stream[i] == '*')
		i++;
	return (i);
}

void	ft_check_precision(t_format *format)
{
	if (format->precision < 0)
	{
		format->precision = 0;
		format->dot = false;
	}
}
