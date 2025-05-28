/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:46:07 by giho              #+#    #+#             */
/*   Updated: 2025/05/28 17:39:21 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 25
#endif

char	*get_next_line(int fd);
ssize_t	read_buffer(char *buffer, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_empty_string(void);
char	*ft_strjoin(char *s1, char const *s2);
void ft_adv(char *buffer, int adv);

#endif