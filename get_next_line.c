/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:04:28 by achristo          #+#    #+#             */
/*   Updated: 2020/02/16 17:33:11 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(int i, char *buffer)
{
	int 	j;
	char	*line;

	j = 0;
	while (buffer[i + j] != '\n' && buffer[i + j] != '\0')
		j++;
	line = (char*)malloc(sizeof(char)*(j + 1));
	j = 0;
	while (buffer[i + j] != '\n' && buffer[i + j] != '\0')
	{
		line[j] = buffer[i + j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static int	i;
	char		*n_buffer;
	int			j;
	static char	*buffer;
	static int	times;

	n_buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, n_buffer, BUFFER_SIZE);
	n_buffer[BUFFER_SIZE] = '\0';
	if (times == 0)
		buffer = ft_strdup("\0");
	buffer = ft_strjoin(buffer,n_buffer);
	times = times + 1;
	*line = ft_line(i, buffer);
	j = ft_strlen(*line);
	i = i + ft_strlen(*line) + 1;
	if (buffer[i - 1] == '\n')
	{
		return (1);
	}
	if (buffer[i - 1] == '\0')
	{
		return (0);
	}
	return (-1);
}
