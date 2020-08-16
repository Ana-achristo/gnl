/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:08:22 by achristo          #+#    #+#             */
/*   Updated: 2020/08/16 11:29:33 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

int	ft_isline(char *s)
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

int	ft_readfile(int fd, int count, char **buf)
{
	int		r;
	char	*new;
	char	*aux;

	if ((new = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	if ((r = read(fd, new, BUFFER_SIZE)) < 0)
		return (-1);
	new[r] = '\0';
	aux = *buf;
	*buf = ft_strjoin(*buf, new);
	free(aux);
	count = ft_isline(*buf);
	if (new[0] == '\0')
		count = 0;
	free(new);
	return (count);
}

int	get_next_line(int fd, char **line)
{
	int			count;
	static char	*buf[OPEN_MAX];
	int			i;
	char		*aux;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (i = 0) != 0)
		return (-1);
	if (buf[fd] == NULL)
		if ((buf[fd] = ft_strdup("")) == NULL)
			return (-1);
	while (count == 1)
		if ((count = ft_readfile(fd, count, &buf[fd])) == -1)
			return (-1);
	while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
		i++;
	if (buf[fd][i] == '\0')
		count = -1;
	*line = ft_substr(buf[fd], 0, i);
	aux = buf[fd];
	buf[fd] = ft_substr(buf[fd], i + 1, (ft_strlen(buf[fd]) - i));
	free(aux);
	if (count == -1)
		return (0);
	return (1);
}
