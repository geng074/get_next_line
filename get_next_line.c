/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:36:01 by giho              #+#    #+#             */
/*   Updated: 2025/10/08 12:23:31 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_strcpy(char *src, char *dest)
{
	int i;
	if (!src || !dest)
		return;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

int ft_strlen(char *str)
{
	int i;
	if (!str)
		return 0;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void ft_strcat(char *buffer, char *output)
{
	int i;
	int len;
	if (!buffer || !output)
		return;

	i = 0;
	len = ft_strlen(output);
	
	while (buffer[i])
	{
		output[len + i ] = buffer [i];
		i++;	
	}
	output[len + i ]  = 0;
	
}

int cr_position(char *str)
{
	int cr_pos;
	
	if (!str)
		return -1;

	cr_pos = 0;
	while (str[cr_pos])
	{
		if (str[cr_pos] == '\n')
			return cr_pos;
		cr_pos++;
			
	}
	return -1;

	
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *buffer_temp;
	int	buffer_cr;
	char *output;
	char *output_temp;
	
	ssize_t	read_total;
	ssize_t read_bytes;
	ssize_t capacity;
	capacity = 4;
	read_total = 0;

	if (fd < 0)
		return NULL;
	if (!buffer)
	{
		// printf("malloc buffer\n");
		buffer = malloc(BUFFER_SIZE +1);
		if (!buffer)
			return NULL;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return NULL;
		}
		buffer[read_bytes] = 0;
		// printf("97 buffer is %s\n", buffer);

		
	}
	output = malloc(capacity +1);
	if (!output)
	{
		free(buffer);
		return NULL;
	}
	output[0]= 0;	
	// ft_strcpy("ab", output);
	// printf("output is %s\n", output);

	
	read_bytes = ft_strlen(buffer);
	
	while (read_bytes > 0)
	{
		if (capacity < read_total + read_bytes)
		{
			while (capacity < read_total + read_bytes)
				capacity = capacity * 2;
			output_temp = malloc(capacity + 1);
			if (!output_temp)
			{
				free(buffer);
				free(output);
				return NULL;
			}
			ft_strcpy(output, output_temp);
			free(output);
			output = output_temp;
			// printf("86 output is %s\n", output);

			
		}
		read_total = read_total + read_bytes;
		// printf("buffer is %s\n", buffer);

		
		buffer_cr = cr_position(buffer);
		if (buffer_cr >= 0)
		{
			buffer_temp = buffer + buffer_cr + 1;
			buffer[buffer_cr] = 0;
			ft_strcat(buffer, output);
			ft_strcat("\n", output);
			// printf("133 output is %s\n", output);
			buffer = buffer_temp;
			// printf("155 buffer is %s\n", buffer);
			return output;
			// read_bytes = ft_strlen(buffer);
			// if (read_bytes == 0)
			// {
			// 	read_bytes = read(fd, buffer, BUFFER_SIZE);
			// 	if (read_bytes < 0)
			// 	{
			// 	free(buffer);
			// 	free(output);
			// 	return NULL;
			// 	}
			// 	buffer[read_bytes] = 0;
			// }
			
		}
		else
		{		
			ft_strcat(buffer, output);
			buffer[0] = 0;
			// printf("140 output is %s\n", output);


			read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (read_bytes < 0)
			{
				free(buffer);
				free(output);
				return NULL;
			}
			buffer[read_bytes] = 0;
		}
	}
	
	
	// if (buffer[0] == 0)
	// 	free(buffer);
	return output;
}

int main()
{
	int fd;
	char *output;
	fd = 0;

	// fd = open("files/empty", O_RDONLY);
	fd = open("input.txt", O_RDONLY);
	// fd = -1;
	output = get_next_line(fd);
	printf("output is %s", output);
	
	printf("\n with feeling \n");
	output = get_next_line(fd);
	printf("output is %s", output);

	printf("\n with feeling \n");
	output = get_next_line(fd);
	printf("output is %s", output);

	
	// printf("str is %d\n", ft_strlen("test"));
	// ft_strcpy("test", test);
	// printf("str2 is %s\n", test);
	close(fd);
}