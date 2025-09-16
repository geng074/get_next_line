/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:36 by giho              #+#    #+#             */
/*   Updated: 2025/05/30 11:12:21 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_empty_string(void)
{
	char	*substr;

	substr = (char *)malloc(1);
	if (!substr)
		return (NULL);
	*substr = '\0';
	return (substr);
}

char	*gnl_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = gnl_strlen(s);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*gnl_helper(t_buffer_state *buf_s, char *output, int fd)
{
	char	*delimit;
	char	*temp;

	while (buf_s->flag >= 0)
	{
		if (buf_s->flag == 0 && buf_s->buf[0] == '\0')
		{
			free(buf_s->buf);
			return (buf_s->buf = NULL, output);
		}
		delimit = gnl_strchr(buf_s->buf, '\n');
		if (delimit)
		{
			temp = gnl_substr(buf_s->buf, 0, (size_t)(delimit - buf_s->buf));
			gnl_adv(buf_s->buf, delimit - buf_s->buf);
			output = gnl_strjoin(output, temp);
			output = gnl_strjoin(output, "\n");
			free(temp);
			break ;
		}
		else
			output = gnl_strjoin(output, buf_s->buf);
		buf_s->flag = gnl_read_buffer(buf_s->buf, fd);
	}
	return (output);
}

char	*get_next_line(int fd)
{
	char					*output;
	static t_buffer_state	buf_s[LIMIT];

	if (fd < 0 || fd >= LIMIT)
		return (NULL);
	output = NULL;
	if (!buf_s[fd].buf)
	{
		buf_s[fd].buf = malloc(BUFFER_SIZE + 1);
		if (!buf_s[fd].buf)
			return (NULL);
		buf_s[fd].buf[0] = '\0';
	}
	if (buf_s[fd].buf[0] == '\0')
		buf_s[fd].flag = gnl_read_buffer(buf_s[fd].buf, fd);
	else
		buf_s[fd].flag = 1;
	if (buf_s[fd].flag == -1)
	{
		free(buf_s[fd].buf);
		buf_s[fd].buf = NULL;
		return (free(output), NULL);
	}
	output = gnl_helper(&buf_s[fd], output, fd);
	return (output);
}
