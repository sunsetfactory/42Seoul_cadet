/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/30 10:48:23 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	buf_stat[BUFFER_SIZE];
	char			*buf_read;
	int				ret;

	if (fd == NULL)
		return (NULL);
	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, *buf_read, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (NULL);
		buf_stat = buf_read;
		if (buf_stat != NULL)
			buf_stat[ret] = '\0';
		
	}
	return *buf_read;
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
  int	fd;
  char	*line;

  fd = 0;
  fd = open("input.txt", O_RDONLY);
  while ((line = get_next_line(fd)) != NULL)
  {
  	printf("%s", line);
	  free(line);
  }
  if (line == NULL)
		printf("%s\n", line);

  close(fd);

  return (0);
}