/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:58:14 by giho              #+#    #+#             */
/*   Updated: 2025/05/28 20:16:45 by giho             ###   ########.fr       */
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
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}	
	
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	
}