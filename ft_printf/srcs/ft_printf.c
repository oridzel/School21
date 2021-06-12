#include <stdarg.h>
#include "ft_parser.h"
#include "libftprintf.h"

int	ft_printf(const char *stream, ...)
{
	int		len;
	va_list	args;

	if (!stream)
		return (-1);
	if (ft_strlen((char *)stream) == 0)
		return (0);
	len = 0;
	va_start(args, stream);
	len = ft_parser((char *)stream, args);
	va_end(args);
	return (len);
}
