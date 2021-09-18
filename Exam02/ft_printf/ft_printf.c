#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	precision;
int	result;
int	width;

static void	ft_putchar(char c)
{
	write(1, &c, 1);
	result++;
}

static void ft_putstr(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!(src) || !(cpy))
		return ((void *)0);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static void ft_prints(char *s)
{
	int	len;
	int	isnull;

	isnull = 0;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		isnull = 1;
	}
	len = ft_strlen(s);
	if (precision != -1 && precision < len)
		len = precision;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	ft_putstr(s, len);
	if (isnull)
		free(s);
}

static char	*ft_itoa(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*digit;

	len = 0;
	digit = NULL;
	temp_nbr = nbr;
	if (nbr == 0)
		len++;	
	while (temp_nbr)
	{
		temp_nbr /= base;
		len++;
	}
	if ((digit = malloc(len + 1)) != NULL)
	{
		digit[len] = '\0';
		while (len-- > 0)
		{
			digit[len] = nbr % base;
			if (nbr % base > 9)
				digit[len] += 'a' - 10;
			else
				digit[len] += '0';
			nbr /= base;
		}
	}
	return (digit);
}

static void ft_printd(long num)
{
	char	*s;
	int		len;
	int		minus = 0;

	if (num < 0)
	{
		minus = 1;
		num = -num;
		width--;
	}
	s = ft_itoa(num, 10);
	len = ft_strlen(s);
	if (precision != -1 && precision > len)
		len = precision;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	if (minus)
		ft_putchar('-');
	while (len > ft_strlen(s))
	{
		ft_putchar('0');
		len--;
	}
	ft_putstr(s, ft_strlen(s));
	free(s);
}

static void ft_printx(unsigned long num)
{
	char	*s;
	int		len;

	s = ft_itoa(num, 16);
	len = ft_strlen(s);
	if (precision != -1 && precision > len)
		len = precision;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	while (len > ft_strlen(s))
	{
		ft_putchar('0');
		len--;
	}
	ft_putstr(s, ft_strlen(s));
	free(s);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;

	result = 0;
	if (str == NULL)
		return (1);
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			precision = -1;
			width = 0;
			str++;
			while (*str <= '9' && *str >= '0')
			{
				width = width * 10 + (*str - '0');
				str++;
			}
			if (*str == '.')
			{
				precision = 0;
				str++;
				while (*str <= '9' && *str >= '0')
				{
					precision = precision * 10 + (*str - '0');
					str++;
				}
			}
			if (*str == 'd')
				ft_printd(va_arg(arg, int));
			else if (*str == 's')
				ft_prints(va_arg(arg, char *));
			else if (*str == 'x')
				ft_printx(va_arg(arg, unsigned int));
			else
				ft_putchar(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (result);
}

int	main(void)
{
	int		c = -2147483648;
	char	*str = "Hello";
	char	*nullstr = NULL;

	printf("%d\n", c);
	ft_printf("%d\n", c);

	printf("%s\n", str);
	ft_printf("%s\n", str);

	printf("%10.3s\n", nullstr);
	ft_printf("%10.3s\n", nullstr);
	
	printf("[%10.2s]\n", "toto");
	ft_printf("[%10.2s]\n", "toto");

	printf("Magic [%s] is [%10.5d]\n", "number", -42);
	ft_printf("Magic [%s] is [%10.5d]\n", "number", -42);

	printf("Hexadecimal for [%.5d] is [%10.5x]\n", -42, 42);
	ft_printf("Hexadecimal for [%.5d] is [%10.5x]\n", -42, 42);

	return (0);
}
