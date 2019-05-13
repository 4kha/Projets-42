#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int fd;
	int fd2;
char *line;
(void)argc;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
}
	return 0;
}
