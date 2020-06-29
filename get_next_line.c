#include "get_next_line.h"
#include <stdio.h>

int	ft_isline(char *s)
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

char	*ft_readfile(int fd)
{
	char *new;
	int		r;

	if ((new = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (NULL);
	if ((r = read(fd, new, BUFFER_SIZE)) < 0)
		return (NULL);
	new[r] = '\0';
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	int			i;
	int			count;
	char		*new;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf == NULL)
		buf = ft_strdup("");
	while (count == 1)
	{	
		if ((new = ft_readfile(fd)) == NULL)
			return (-1);
		buf = ft_strjoin(buf, new);
		free(new);
		count = ft_isline(buf);
		if (new[0] == '\0')
			count = 0;
	}
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		*line = buf;
		buf = ft_substr(buf, ft_strlen(buf), 0);
		return (0);
	}
	*line = ft_substr(buf, 0, i);
	buf = ft_substr(buf, i + 1, ft_strlen(buf));
	return (1);
}
