#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_number
{
	char				sign;
	unsigned long long	value;
	unsigned char		base;
}				t_number;

typedef struct s_format
{
	bool		minus : 1;
	bool		zero : 1;
	bool		space : 1;
	bool		plus : 1;
	bool		dot : 1;
	int			width;
	int			precision;
	int			printed_length;
	char		type;
}	t_format;

int		ft_parser(char *stream, va_list args);
int		ft_parse_format(char *stream, t_format *format, va_list args, int i);
int		ft_parse_width(char *stream, t_format *format, va_list args, int i);
int		ft_parse_minus(char *stream, t_format *format, va_list args, int i);
int		ft_parse_precision(char *stream, t_format *format, va_list args, int i);
int		ft_parse_star(char *stream, t_format *format, va_list args, int i);
void	ft_check_precision(t_format *format);
int		ft_numlen(long n);
void	ft_parse_type(char stream, t_format *format);
int		ft_parse_zero(char *stream, t_format *format, int ind);

#endif
