#include "get_next_line.h"
#include <fcntl.h>

void check_leaks();

int	main(void)
{
	int		fd;
	char	*line;
	int		num_lines_read = 0;

	fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	
	while (get_next_line(fd, &line))
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