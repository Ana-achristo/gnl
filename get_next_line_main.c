#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main ()
{
	int fd;
//	int fd2;
	char *line;

	line = (char*)malloc(100*sizeof(char*));
	fd = open ("texto", O_RDONLY);
//	fd2 = open ("texto2", O_RDONLY);
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	printf("\nsegunda rodada\n");
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
	printf("\nterceira rodada\n");
	printf("retorno %d\n", get_next_line(fd, &line));
	printf("linha %s\n", line);
/*	printf("\nquarta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("\nquinta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("\nsexta rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);
	printf("\nsetima rodada\n");
	printf("retorno %d\n", get_next_line(fd2, &line));
	printf("linha %s\n", line);*/
	return(0);
}
