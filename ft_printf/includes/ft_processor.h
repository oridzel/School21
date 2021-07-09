#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include <stdarg.h>
# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include "ft_parser.h"

void		ft_processor(t_format *format, va_list args);
int			ft_process_d(t_format *format, long long nb,
				unsigned char base, int capital);
int			ft_process_str(t_format *format, char *str);
int			ft_process_chr(t_format *format, char c);
int			ft_process_ptr(t_format *format, unsigned long long addr,
				int capital);
t_number	*ft_init_number(long long nb, unsigned char base);
int			ft_calculate_number_length(unsigned long long n,
				unsigned char base);
char		*ft_process_itoa(unsigned long long nb, unsigned char base,
				int capital);
void		ft_putstr(char *s, int length, int fd);
char		ft_padding_char(t_format *format);
int			ft_padding(int width, int length, char c);
int			ft_padding_auto(char c, int padding_width, unsigned int size);
int			ft_padding_left(t_format *format, char c, unsigned int size);
int			ft_padding_right(t_format *format, char c, unsigned int size);

#endif
