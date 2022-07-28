#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	char *s;
	int fd = open("text", O_RDWR);
	s = (char *)1;
	while (s)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
	}
	return 0;
}
