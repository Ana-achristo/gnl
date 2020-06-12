#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char	*buf;
	char	*new;
	int	r;
	int i;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf == NULL)
		buf = ft_strdup("");
	i = 0;	
	if ((new = (char*)malloc(sizeof(char)*(BUFFER_SIZE+1))) == NULL)
		return (-1);
	if ((r = read(fd, new, BUFFER_SIZE)) < 0)
		return (-1);
	new[r] = '\0';
	buf = ft_strjoin(buf, new);
	
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i+1] == '\0')
	{
		*line = buf;	
		return (0);
	}
	*line = ft_substr(buf, 0, i);
	buf = ft_substr(buf, i+1, ft_strlen(buf));
	free(new);
	return(1);	
}
