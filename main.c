#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

void ft_putstr(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(void)
{
	char *line;
	int ret;
	int fd;
	//int fd1;
	fd = open("get_next_line.c", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
		if (ret == 0)
			break;
	}

/*
fd1 = open("get_next_line_utils.c", O_RDONLY);
while ((ret = get_next_line(fd1, &line)) >= 0)
{
	ft_putstr(line);
	ft_putstr("\n");
	free(line);
	if (ret == 0)
		break;
}
close(fd1);
*/
close(fd);
}