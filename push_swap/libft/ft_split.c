/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:36:45 by szeratul          #+#    #+#             */
/*   Updated: 2021/10/04 15:36:45 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char delim)
{
	char	*word;
	int		count;

	count = 0;
	word = str;
	while (*word)
	{
		while (*word && *word == delim)
			word++;
		if (*word && *word != delim)
		{
			count++;
			while (*word && *word != delim)
				word++;
		}
	}
	return (count);
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**malloc_error(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

static char	**put_words(char *str, char **words, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (*str)
	{
		j = 0;
		while (*str && *str == c)
			str++;
		while (*(str + j) && *(str + j) != c)
			j++;
		if (*str && *str != c)
		{
			word = (char *)malloc(sizeof(char) * (j + 1));
			if (!word)
				return (malloc_error(words));
			ft_strncpy(word, str, j);
			words[i++] = word;
			while (*str && *str != c)
				str++;
		}
	}
	words[i] = (void *)0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;

	if (!s)
		return ((void *)0);
	count = count_words((char *)s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	words = put_words((char *)s, words, c);
	return (words);
}
