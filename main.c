#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	char *s;
	int fd = open("text.txt", O_RDWR);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s\n", s);
		s = get_next_line(fd);
	}
	return 0;
}
