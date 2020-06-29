#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main ()
{
	int fd;
	int fd2;
	char *line;

	fopen("texto3", "ABC");
	line = (char*)malloc(100*sizeof(char*));
	fd = open ("texto", O_RDONLY);
	fd2 = open ("texto2", O_RDONLY);
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	printf("segunda rodada\n");
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	printf("terceira rodada\n");
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	printf("quarta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("quinta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("sexta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("setima rodada\n");
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	return(0);
}
