#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(char **line)
{
	int		rd = 0;
	int		i = 0;
	char	ch;
	char	*buffer = malloc(100000);
	*line = buffer;
	while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
		buffer[i++] = ch;
	buffer[i] = '\0';
	return (rd);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		num_lines_read = 0;

	fd = open("test", O_RDONLY);
	
	while (get_next_line(&line))
	{
		num_lines_read++;
		printf("%s\n", line);
		free(line);
	}
	num_lines_read++;
	printf("%s\n", line);
	free(line);

	close(fd);
	printf("Number of lines read: %d\n", num_lines_read);

	// sleep(100);
	// check_leaks();

	return (0);
}