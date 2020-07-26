/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:08:22 by achristo          #+#    #+#             */
/*   Updated: 2020/07/26 11:31:36 by achristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	size1;
	size_t	size2;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if ((sjoin = malloc((size1 + size2 + 1) * sizeof(char))) == 0)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		sjoin[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		sjoin[size1 + i] = s2[i];
		i++;
	}
	sjoin[size1 + i] = '\0';
	return (sjoin);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	s1_copy = malloc((len + 1) * sizeof(char));
	if (s1_copy == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		s1_copy[i] = s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	start_copy;
	size_t	len_s;

	len_s = ft_strlen(s);
	start_copy = ((size_t)start);
	if (s == 0)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len && start_copy < len_s)
	{
		sub[i] = s[start_copy + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
