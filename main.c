#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line) 
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
