/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:54 by giho              #+#    #+#             */
/*   Updated: 2025/05/28 20:16:10 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total;
	size_t			size_max;

	size_max = (size_t)-1;
	if (size != 0 && nmemb > size_max / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr && total != 0)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strchr(const char *s, int c)
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


char	*ft_empty_string(void)
{
	char	*substr;

	substr = (char *)malloc(1);
	if (!substr)
		return (NULL);
	*substr = '\0';
	return (substr);
}


size_t	ft_strlen(const char *str)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_start;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_start = (size_t)start;
	if (sub_start > s_len)
		return (ft_empty_string());
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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	s1_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2 != '\0')
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	free(s1 - s1_len);
	return (str - len);
}

void ft_adv(char *buffer, int adv)
{
	int i;
	i = 0;
	while (i < BUFFER_SIZE - 1 + adv && buffer[i + adv + 1] != '\0') 
	{
		buffer[i] = buffer[i + adv + 1];
		i++;
	}
	buffer[i] = '\0';
}
ssize_t	read_buffer(char *buffer, int fd)
{
	int result;
	ssize_t bytes_read;
	
	
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		//printf("Error reading file");
		return (-1);
	}
	
	if (bytes_read < BUFFER_SIZE)
	{
		//printf("end of file");
		return (0);
	}
	
	return (bytes_read);
}
