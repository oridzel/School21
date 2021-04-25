#include "libft.h"

static int	calculate_length(int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	if (n == 0)
		length++;
	else
	{
		while (n > 0)
		{
			n /= 10;
			length++;
		}
	}
	return (length);
}

static void	reverse(char *str, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = n - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

static int	compose(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 9)
		str[i++] = n + '0';
	else
	{
		while (n > 0)
		{
			str[i++] = n % 10 + '0';
			n /= 10;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (calculate_length(n) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	i = compose(str, n);
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}
