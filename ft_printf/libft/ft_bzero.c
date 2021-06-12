void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*dst;

	dst = s;
	if (n > 0)
	{
		while (n != 0)
		{
			*dst++ = 0;
			n--;
		}
	}
}
