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
		printf("\\%s", s);
		s = get_next_line(fd);
	}
	close(fd);
	int fd2 = open("text.txt", O_RDWR);
	s = get_next_line(fd2);
	while (s)
	{
		printf("\\%s", s);
		s = get_next_line(fd);
	}
	close(fd2);
	return 0;
}
