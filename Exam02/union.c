#include <unistd.h>

int		check_dup(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2, int *p)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!check_dup(s2, s1[i]))
		{
			write(1, &s1[i], 1);
			s2[*p] = s1[i];
			(*p)++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	s[1024];
	int		p;

	if (argc == 3)
	{
		ft_union(argv[1], s, &p);
		ft_union(argv[2], s, &p);
	}
	write(1, "\n", 1);
	return (0);
}