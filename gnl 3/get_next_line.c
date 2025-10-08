/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:59:45 by giho              #+#    #+#             */
/*   Updated: 2025/10/01 16:56:07 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int len;
	
	if (!str)
		return 0;
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
	
}

void ft_memmove(char *src, char *dest)
{
	int i;
	int len;
	int dest_len;
	if (!src)
		return;
	len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	
	i = 0;
	while (i < len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	
	
}

void ft_memmove2(char *src, char *dest, int start)
{
	int i;
	int src_len;
	if (!src)
		return;

	src_len = ft_strlen(src);
	i = 0;
	while ((i + start) < src_len)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = 0;
}

int	has_return(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return i;
		}
		i++;
	}
	return -1;
}
char *get_next_line(int fd)
{
	static t_buf	buf;
	// char	*buffer;
	char	*output;
	char	*buf_temp;
	char	*temp;
	// int		len;
	int 	return_position;
	ssize_t	read_bytes;
	ssize_t 	read_total;
	ssize_t	capacity;
	capacity = 5;
	read_total = 0;

	if (fd < 0)
	{
		return NULL;
	}

	if ((buf.buf_flag == 1) && buf.buffer)
	{
		// len = ft_strlen(buf.buffer);
		// printf("107 buffer is %s, len is %d\n", buf.buffer, len);

		
		read_bytes = ft_strlen(buf.buffer);
		if (read_bytes == 0)
		read_bytes = read(fd, buf.buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buf.buffer);
			return NULL;
		}
		buf.buffer[read_bytes] = 0;
		
	}
	else
	{
		buf.buffer = malloc(BUFFER_SIZE + 1 );
		// buf.buf_flag = 1;
		if (!buf.buffer)
			return NULL;
	
		read_bytes = read(fd, buf.buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buf.buffer);
			return NULL;
		}
		buf.buffer[read_bytes] = 0;
	}

	// if (read_bytes == 0)
	// {
	// 	free(buf.buffer);
	// 	return NULL;
	// }
	
	output = malloc(capacity + 1 );
	if (!output)
	{
		free(buf.buffer);
		return NULL;
	}
	output[0] = 0;
	
	while (read_bytes > 0)
	{
		// len = ft_strlen(buf.buffer);
		// printf("82 buffer is %s, len is %d\n", buf.buffer, len);

		if (read_total + read_bytes > capacity)
		{
			while (read_total + read_bytes > capacity)
			{
				capacity = capacity * 2;
			}
			temp = malloc(capacity + 1);
			if (!temp)
			{
				free(buf.buffer);
				free(output);
				return NULL;
			}
			temp[0] = 0;
			ft_memmove(output, temp);
			free(output);
			output = temp;
		}

		return_position = has_return(buf.buffer);
		if (return_position > 0)
		{
			buf.buf_flag = 1;
			buf_temp = malloc(BUFFER_SIZE + 1);
			if (!buf_temp)
			{
				free(buf.buffer);
				free(output);
				return NULL;
			}
			ft_memmove2(buf.buffer, buf_temp, return_position);
			buf.buffer[return_position] = 0;
			
			ft_memmove(buf.buffer, output + read_total);
			read_total = read_total + read_bytes;
			output[read_total] = 0;
			free(buf.buffer);
			buf.buffer = buf_temp;
			return (output);
			
		}

		
		// len = ft_strlen(buf.buffer);
		// printf("192 buffer is %s, len is %d\n", buf.buffer, len);
		// len = ft_strlen(output);
		// printf("194 output is %s, len is %d\n", output, len);

		
		ft_memmove(buf.buffer, output + read_total);
		read_total = read_total + read_bytes;
		output[read_total] = 0;
		
		
		// len = ft_strlen(output);
		// printf("106 output is %s, len is %d\n", output, len);

		
		read_bytes = read(fd, buf.buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buf.buffer);
			free(output);
			return NULL;
		}
		buf.buffer[read_bytes] = 0;
	}
	free(buf.buffer);
	buf.buffer = NULL;
	
	return output;
	
	
}

// int main ()
// {
// 	int fd;
// 	int len;
// 	char	*output;

// 	fd = open("input.txt", O_RDONLY);
// 	fd = 1000;
	
// 	output = get_next_line(fd);
// 	len = ft_strlen(output);

// 	printf("output is %s, len is %d\n", output, len);

	
// 	output = get_next_line(fd);
// 	len = ft_strlen(output);

// 	printf("output is %s, len is %d\n", output, len);
// }