/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:45:36 by giho              #+#    #+#             */
/*   Updated: 2025/05/28 18:26:54 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*output;
	char		*temp;
	char	*delimit;
	static  char	buffer[BUFFER_SIZE];
	static ssize_t	flag;


	
	
	output = ft_empty_string();
	if (buffer[0] == '\0')
		flag = read_buffer(buffer, fd);
	else
		flag = 1;
	while (flag >= 0)
	{
	
	
		delimit = ft_strchr(buffer, '\n');
		if (delimit)
		{
			temp = ft_substr(buffer,0,(size_t)(delimit - buffer));
			printf("flag1 : %zd\n", flag);
			fflush(stdout);
			ft_adv(buffer, delimit - buffer );
			printf("flag2: %zd\n", flag);
			fflush(stdout);
			// printf("temp is %s\n",temp);
			// fflush(stdout);
			//flag = -2;
			output = ft_strjoin(output,temp);
			// printf("1output is %s\n",output);
			// fflush(stdout);
			free(temp);
			
			break;
		}
		else
		{
			output = ft_strjoin(output,buffer);
			// printf("2output is %s\n",output);
			// fflush(stdout);
		}
		flag = read_buffer(buffer, fd);

	}
	printf("next line is %s", output);
	printf("\n");


	return (NULL);
	
}