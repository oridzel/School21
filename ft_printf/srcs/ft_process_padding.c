#include "ft_processor.h"

char	ft_padding_char(t_format *format)
{
	if (format->zero == 0)
		return (' ');
	else
		return ('0');
}

int	ft_padding(int width, int length, char c)
{
	int	i;

	i = 0;
	while (width > length)
	{
		ft_putchar_fd(c, 1);
		width--;
		i++;
	}
	return (i);
}

int	ft_padding_auto(char c, int padding_width, unsigned int size)
{
	int	i;

	i = 0;
	if (padding_width > (int)size)
		i = ft_padding(padding_width, size, c);
	return (i);
}

int	ft_padding_left(t_format *format, char c, unsigned int size)
{
	int	i;

	i = 0;
	if (format->minus == 0)
		i = ft_padding_auto(c, format->width, size);
	return (i);
}

int	ft_padding_right(t_format *format, char c, unsigned int size)
{
	int	i;

	i = 0;
	if (format->minus != 0)
		i = ft_padding_auto(c, format->width, size);
	return (i);
}
