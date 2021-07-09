#include "ft_processor.h"

int	ft_treat_null_ptr(t_format *format, int i)
{
	i += ft_padding_left(format, ' ', 2);
	ft_putstr_fd("0x", 1);
	i += ft_padding_right(format, ' ', 2);
	return (i + 2);
}

int	ft_process_ptr(t_format *format, unsigned long long addr, int capital)
{
	int		i;
	int		len;
	int		actual_size;
	char	*str;

	i = 0;
	if (addr == 0 && format->dot && format->precision == 0)
		return (ft_treat_null_ptr(format, i));
	str = ft_process_itoa(addr, 16U, capital);
	len = (int)ft_strlen(str);
	actual_size = len + 2;
	if (format->dot && format->precision > actual_size)
		actual_size = format->precision;
	i += ft_padding_left(format, ' ', actual_size);
	ft_putstr_fd("0x", 1);
	i += 2;
	if (format->dot && format->precision >= 0 && len < format->precision)
		i += ft_padding(actual_size, len, '0');
	ft_putstr(str, len, 1);
	i += len;
	i += ft_padding_right(format, ' ', actual_size);
	free(str);
	return (i);
}
