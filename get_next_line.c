#include "get_next_line.h"

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

int	ft_readfile(int fd, int count, char **buf)
{
	char		*new;
	int		r;

	if ((new = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	if ((r = read(fd, new, BUFFER_SIZE)) < 0)
		return (-1);
	new[r] = '\0';
	*buf = ft_strjoin(*buf, new);
	free(new);
	count = ft_isline(*buf);
	if (new[0] == '\0')
		count = 0;
	return (count);
}

int	get_next_line(int fd, char **line)
{
	int count;
	static char	*buf;
	int			i;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf == NULL)
		buf = ft_strdup("");
	while (count == 1)
		if ((count = ft_readfile(fd, count, &buf)) == -1)
			return (-1);
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
