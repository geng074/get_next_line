/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:29:40 by giho              #+#    #+#             */
/*   Updated: 2025/09/16 11:47:28 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;
	if (!str)
		return 0;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
	
}

void ft_memcpy(char *src, char *dest, int len)
{
	int dest_start;
	int i;
	
	if (!src || !dest)
		return;
	dest_start = ft_strlen(dest);
	
	i = 0;
	while (i < len)
	{
		dest[dest_start + i] = src[i];
		i++;
	}
	dest[dest_start + i] = 0;	

}

char *get_next_line(int fd)
{
	static char *buffer;
	char *output;
	char	*temp;
	int capacity = 3;
	ssize_t read_bytes;
	ssize_t read_total;

	if (fd < 0)
		return (NULL);
	read_total = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		fprintf(stderr, "malloc failed");
		return NULL;
	}
	buffer[0] = 0;
	
	output = malloc((capacity + 1) * sizeof(char));
	if (!output)
	{
		fprintf(stderr, "malloc failed");
		free(buffer);
		return NULL;
	}
	output[0] = 0;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes)
	{
		buffer[read_bytes] = 0;
		// printf("buffer is %s\n", buffer);

		if (read_total + read_bytes > capacity)
		{
			while (read_total + read_bytes > capacity)
				capacity = capacity *2;
			
			temp = malloc((capacity + 1) * sizeof(char));
			temp[0] = 0;
			if (!output)
			{
				fprintf(stderr, "malloc failed");
				free(buffer);
				free(temp);
				return NULL;
			}
			ft_memcpy(output, temp, read_total);
			
			temp[read_total] = 0;
			free(output);
			output = temp;
			// printf("97 output is %s\n", output);

		}
		ft_memcpy(buffer, output, ft_strlen(buffer));
		read_total = read_total + read_bytes;
		output[read_total] = 0;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return output;
}
 int main()
 {
	int	fd;
	char dest[10];
	char *output;
	// dest[0] = 'd';
	// dest[1] = 0;
	fd = open("input.txt", O_RDONLY);
	output = get_next_line(fd);
	printf("output is %s\n", output);
	free(output);
	// printf("str len is %d\n",ft_strlen("aaa "));
	// ft_memcpy("aaa", dest, 3);
	// printf("dest is %s\n", dest);

 }