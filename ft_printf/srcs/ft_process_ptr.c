#include "ft_processor.h"
#include <stdio.h>

int	ft_process_ptr(t_format *format, unsigned long long addr, int capital)
{
	int		i;
	int		len;
	int		actual_size;
	char	*str;

	str = ft_process_itoa(addr, 16U, capital);
	i = 0;
	len = (int)ft_strlen(str);
	actual_size = len + 2;
	if (format->dot == 1 && format->precision > actual_size)
		actual_size = format->precision;
	i += ft_padding_left(format, ' ', actual_size);
	ft_putstr_fd("0x", 1);
	if (format->dot == 1 && len < format->precision)
		i += ft_padding(actual_size, len, '0');
	ft_putstr(str, len, 1);
	i += (2 + len);
	i += ft_padding_right(format, ' ', actual_size);
	free(str);
	return (i);
}
