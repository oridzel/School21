#include "get_next_line.h"
#include <fcntl.h>

static char	*ft_realloc(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	dest = ft_strdup(src);
	if (temp != NULL)
		free(temp);
	return (dest);
}

static char	*ft_realloc_and_join(char *line, char *buffer)
{
	char	*temp;

	temp = line;
	if (line == NULL)
		line = ft_strjoin("\0", buffer);
	else
		line = ft_strjoin(line, buffer);
	if (temp != NULL)
		free(temp);
	return (line);
}

static char	*check_what_left(char **left, char **line)
{
	char	*end_of_line;
	char	*temp;

	end_of_line = NULL;
	if (*left)
	{
		end_of_line = ft_strchr(*left, '\n');
		if (end_of_line)
		{
			*end_of_line = '\0';
			*line = ft_realloc(*line, *left);
			temp = ft_strdup(++end_of_line);
			free(*left);
			*left = temp;
		}
		else
		{
			*line = ft_realloc(*line, *left);
			free(*left);
			*left = NULL;
		}
	}
	return (end_of_line);
}

static int	check_if_nl(int bytes_read, char *buffer, char **left,
				char **end_of_line)
{
	*end_of_line = ft_strchr(buffer, '\n');
	if (*end_of_line)
	{
		**end_of_line = '\0';
		if (bytes_read > 1)
		{
			*left = ft_realloc(*left, ++(*end_of_line));
			if (left == NULL)
				return (-1);
		}
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*end_of_line;
	int			bytes_read;
	static char	*left = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	end_of_line = check_what_left(&left, line);
	bytes_read = 1;
	while (!end_of_line && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (clear_all(line, left));
		buffer[bytes_read] = '\0';
		if (check_if_nl(bytes_read, buffer, &left, &end_of_line) == -1)
			return (clear_all(line, left));
		*line = ft_realloc_and_join(*line, buffer);
		if (line == NULL)
			return (clear_all(line, left));
	}
	if (bytes_read == 0 && ft_strlen(left) == 0)
		return (0);
	return (1);
}
