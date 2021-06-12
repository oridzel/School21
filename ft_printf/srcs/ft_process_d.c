#include "ft_processor.h"

int	ft_number_prefix(t_format *format, t_number *number, unsigned int size)
{
	int	i;

	i = 0;
	if (format->space == 1 && number->sign != '-')
		i += write(1, " ", 1);
	if (format->zero == 0)
		i += ft_padding_left(format, ft_padding_char(format), size);
	if (number->sign == '-' || format->plus == 1)
	{
		ft_putchar_fd(number->sign, 1);
		i++;
	}
	if (format->zero != 0)
		i += ft_padding_left(format, ft_padding_char(format), size);
	return (i);
}

static unsigned int	ft_calculate_actual_size(
	t_format *format, t_number *number, unsigned int size)
{
	unsigned int	len;

	if (format->dot == 1 && format->precision > (int)size)
		len = format->precision;
	else
		len = size;
	if (number->sign == '-')
		len++;
	return (len);
}

int	ft_process_d(t_format *format, long long nb,
	unsigned char base, int capital)
{
	int				i;
	t_number		*number;
	char			*str;
	unsigned int	len;
	unsigned int	size;

	i = 0;
	if (nb == 0 && format->precision == 0 && format->dot == 1)
		return (ft_padding(format->width, 0, ' '));
	number = ft_init_number(nb, base);
	str = ft_process_itoa(number->value, number->base, capital);
	len = ft_strlen(str);
	size = ft_calculate_actual_size(format, number, len);
	i += ft_number_prefix(format, number, size);
	if (format->precision != 0 && format->dot != 0)
		i += ft_padding_auto('0', format->precision, len);
	ft_putstr(str, (int)len, 1);
	i += (int)len;
	i += ft_padding_right(format, ft_padding_char(format), size);
	free(number);
	free(str);
	return (i);
}
