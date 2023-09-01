#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(void)
{
	int		i, k;
	int		fd;
	char	*line;

	i = 0;
	k = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	while((k = get_next_line(fd, &line)) > 0)
	{
		printf("%d: %s\n", i++, line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
