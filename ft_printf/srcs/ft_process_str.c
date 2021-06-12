#include "ft_processor.h"
#include <stdio.h>

int	ft_process_chr(t_format *format, char c)
{
	int	len;
	int	i;

	len = 1;
	i = 0;
	if (format->width > len)
		len = format->width;
	if (format->minus == 0)
		i += ft_padding(len, 1, ft_padding_char(format));
	ft_putchar_fd(c, 1);
	i++;
	if (format->minus == 1)
		i += ft_padding(len, 1, ' ');
	return (i);
}

int	ft_process_str(t_format *format, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (str == NULL)
		str = "(null)";
	if (format->dot == 1 && format->precision == 0)
		return (ft_padding(format->width, 0, ' '));
	else
	{
		len = ft_strlen(str);
		if (format->dot == 1 && format->precision < len)
			len = format->precision;
		i += ft_padding_left(format, ' ', len);
		ft_putstr(str, len, 1);
		i += len;
		i += ft_padding_right(format, ' ', len);
	}
	return (i);
}
