#include <unistd.h>

int		check_dup(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		if (!check_dup(str1, str1[i], i))
		{
			j = 0;
			while (str2[j])
			{
				if (str1[i] == str2[j])
				{
					write(1, &str1[i], 1);
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}