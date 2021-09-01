/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:05:49 by szeratul          #+#    #+#             */
/*   Updated: 2021/09/01 12:09:08 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_paths(char **words)
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

char	*free_temp(char *tofree)
{
	free(tofree);
	return (NULL);
}

char	**parse_envp(char **envp)
{
	char	**paths;
	char	*current_line;
	char	*result;

	paths = NULL;
	while (*envp)
	{
		current_line = *envp++;
		result = ft_strnstr(current_line, "PATH=", ft_strlen(current_line));
		if (result)
		{
			paths = ft_split(result + 5, ':');
			break ;
		}
	}
	return (paths);
}
