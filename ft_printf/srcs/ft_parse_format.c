#include "ft_parser.h"
#include "ft_processor.h"

void	ft_parse_type(char stream, t_format *format)
{
	if (ft_strchr("diupxXcs%", stream))
		format->type = stream;
}

int	ft_parse_zero(char *stream, t_format *format, int ind)
{
	int	i;

	i = 0;
	ind++;
	format->zero = true;
	while (stream[ind] == '0')
		ind++;
	if (ft_isdigit(stream[ind]))
	{
		i = ft_atoi(&stream[ind]);
		ind += ft_numlen(i);
	}
	format->width = i;
	return (ind);
}

int	ft_parse_space(t_format *format, int i)
{
	i++;
	format->space = true;
	return (i);
}

int	ft_parse_plus(t_format *format, int i)
{
	i++;
	format->plus = true;
	return (i);
}

int	ft_parse_format(char *stream, t_format *format, va_list args, int i)
{
	while (!(ft_isalpha(stream[i]) || stream[i] == '%') && stream[i] != '\0')
	{
		if (stream[i] == '0')
			i = ft_parse_zero(stream, format, i);
		if (stream[i] == '-')
			i = ft_parse_minus(stream, format, args, i);
		if (stream[i] == ' ')
			i = ft_parse_space(format, i);
		if (stream[i] == '+')
			i = ft_parse_plus(format, i);
		if (stream[i] == '*')
			i = ft_parse_star(stream, format, args, i);
		if (stream[i] == '.')
			i = ft_parse_precision(stream, format, args, i);
		if (ft_isdigit(stream[i]))
			i = ft_parse_width(stream, format, args, i);
	}
	ft_parse_type(stream[i], format);
	if (format->dot)
		format->zero = false;
	ft_processor(format, args);
	if (stream[i] != '\0')
		i++;
	return (i);
}
