#include "get_next_line.h"
#include <stdio.h>

int ft_isline(char *s)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}



int get_next_line(int fd, char **line)
{
	static char	*buf;
	char	*new;
	int	r;
	int i;
	int count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf == NULL)
		buf = ft_strdup("");
	while (count == 1)
	{
		if ((new = (char*)malloc(sizeof(char)*(BUFFER_SIZE+1))) == NULL)
			return (-1);	
		if ((r = read(fd, new, BUFFER_SIZE)) < 0)
			return (-1);
	//	printf("r=%d\n", r);
		new[r] = '\0';
	//	printf("new = \n%s\n", new);
		buf = ft_strjoin(buf, new);
		free(new);
		count = ft_isline(buf);
		if (r == 0)
			count = 0;
	}
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i]  == '\0')
	{
		*line = buf;
		buf = ft_substr(buf, ft_strlen(buf), 0);
		return (0);
	}
	*line = ft_substr(buf, 0, i);
	buf = ft_substr(buf, i+1, ft_strlen(buf));
	//printf("buf = \n%s\n", buf);
	return(1);
}
