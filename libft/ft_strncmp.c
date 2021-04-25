int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i]) && (i < n)
		&& ((unsigned char)s1[i] != '\0') && ((unsigned char)s2[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
