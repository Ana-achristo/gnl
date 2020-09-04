/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:08:22 by achristo          #+#    #+#             */
/*   Updated: 2020/09/04 17:01:45 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

int		ft_isline(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

int		ft_readfile(int fd, int i, char **buf)
{
	int		r;
	char	*new;
	char	*aux;

	if ((new = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	if ((r = read(fd, new, BUFFER_SIZE)) < 0)
	{
		new = ft_free(new);
		return (-1);
	}
	new[r] = '\0';
	aux = ft_strjoin(*buf, new);
	*buf = ft_free(*buf);
	*buf = aux;
	i = ft_isline(*buf);
	if (new[0] == '\0')
		i = 0;
	new = ft_free(new);
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf[OPEN_MAX];
	int			i;
	char		*aux;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (buf[fd] == NULL)
		if ((buf[fd] = ft_strdup("")) == NULL)
			return (-1);
	while (i == 1)
		if ((i = ft_readfile(fd, i, &buf[fd])) == -1)
			return (-1);
	while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
		i++;
	*line = ft_substr(buf[fd], 0, i);
	if (buf[fd][i] == '\0')
	{
		buf[fd] = ft_free(buf[fd]);
		return (0);
	}
	aux = ft_substr(buf[fd], i + 1, (ft_strlen(buf[fd]) - i));
	buf[fd] = ft_free(buf[fd]);
	buf[fd] = aux;
	return (1);
}
