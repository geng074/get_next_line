/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:58:14 by giho              #+#    #+#             */
/*   Updated: 2025/05/29 14:18:39 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	// char *output = "";
	// char *temp = "abc";

	printf("Buffer size is %d\n",BUFFER_SIZE);

	// output = ft_strjoin(output,temp);
	// printf("string is %s",output);
	
	fd = open("example.txt",O_RDONLY);
	// if (fd == -1)
	// {
	// 	perror("Error opening file");
	// 	return 1;
	// }	
	
	printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));

	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	
	close(fd);
	
}