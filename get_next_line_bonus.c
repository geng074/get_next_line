/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:36 by giho              #+#    #+#             */
/*   Updated: 2025/05/29 17:38:05 by giho             ###   ########.fr       */
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

static char	*get_next_line_helper(t_buffer_state *buffer_state,
			char *output, int fd)
{
	char	*delimit;
	char	*temp;
	
	while (buffer_state->flag >= 0)
	{
		if (buffer_state->flag == 0 && buffer_state->buffer[0] == '\0')
			return (output);
		delimit = gnl_strchr(buffer_state->buffer, '\n');
		if (delimit)
		{
			temp = gnl_substr(buffer_state->buffer, 0,
					(size_t)(delimit - buffer_state->buffer));
			gnl_adv(buffer_state->buffer, delimit - buffer_state->buffer);
			output = gnl_strjoin(output, temp);
			output = gnl_strjoin(output, "\n");
			free(temp);
			break ;
		}
		else
		{
			output = gnl_strjoin(output, buffer_state->buffer);
		}
		buffer_state->flag = gnl_read_buffer(buffer_state->buffer, fd);
	}
	return (output);
}

char	*get_next_line(int fd)
{
	char					*output;
	static t_buffer_state	buffer_state[FD_LIMIT];


	if (fd < 0 || fd >= FD_LIMIT)
    return NULL;

	

	
	// if (fd == -1)
	// {
	// 	return (NULL);
	// }
	output = NULL;
	
	if (!buffer_state[fd].buffer)
	{
		buffer_state[fd].buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer_state[fd].buffer)
			return (NULL);
		buffer_state[fd].buffer[0] = '\0'; 
	}
	
	
	
	if (buffer_state[fd].buffer[0] == '\0')
		buffer_state[fd].flag = gnl_read_buffer(buffer_state[fd].buffer, fd);
	else
		buffer_state[fd].flag = 1;
	if (buffer_state[fd].flag == -1)
	{
		free(buffer_state[fd].buffer);
		buffer_state[fd].buffer = NULL;
		free(output);
		return (NULL);
	}
	output = get_next_line_helper(&buffer_state[fd], output, fd);
	return (output);
}
