/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:54 by giho              #+#    #+#             */
/*   Updated: 2025/05/30 11:00:18 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_start;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	sub_start = (size_t)start;
	if (sub_start > s_len)
		return (gnl_empty_string());
	if (sub_start + len > s_len)
		len = s_len - sub_start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len) && s[i + sub_start] != '\0')
	{
		substr[i] = s[i + sub_start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	s1_len;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	s1_len = gnl_strlen(s1);
	len = s1_len + gnl_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		*str++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*str++ = *s2++;
	}
	*str = '\0';
	free(s1 - s1_len);
	return (str - len);
}

void	gnl_adv(char *buf, int adv)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE - 1 + adv && buf[i + adv + 1] != '\0')
	{
		buf[i] = buf[i + adv + 1];
		i++;
	}
	buf[i] = '\0';
}

ssize_t	gnl_read_buffer(char *buf, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		return (-1);
	}
	if (bytes_read < BUFFER_SIZE)
	{
		buf[bytes_read] = '\0';
		return (0);
	}
	buf[bytes_read] = '\0';
	return (bytes_read);
}
