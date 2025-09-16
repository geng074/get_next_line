/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:46:07 by giho              #+#    #+#             */
/*   Updated: 2025/05/30 11:19:49 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
// # include <stdio.h>
# include <unistd.h>
// # include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# ifndef LIMIT
#  define LIMIT 1024
# endif

typedef struct s_buffer_state
{
	int		fd;
	char	*buf;
	ssize_t	flag;		
}	t_buffer_state;
char	*get_next_line(int fd);
ssize_t	gnl_read_buffer(char *buf, int fd);
char	*gnl_strchr(const char *s, int c);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
char	*gnl_empty_string(void);
char	*gnl_strjoin(char *s1, char const *s2);
void	gnl_adv(char *buf, int adv);
char	*gnl_strdup(const char *s);

#endif