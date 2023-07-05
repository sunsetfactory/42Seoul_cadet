/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/07/05 21:27:49 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*buf_cut(char *buf_stat)
{
	char	*line;
	int		i;

	i = 0;
	if (*(buf_stat) == '\0')
		return (NULL);
	while (*(buf_stat + i) != '\n' && *(buf_stat + i) != '\0')
		i++;
	if (*(buf_stat + i) == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i);
	while ()

	return (line);
}

// void	buf_memory_allocation(int fd, char **buf_read, char **buf_stat)
char	*buf_memory_allocation(int fd, char **buf_stat)
{
	int		ret_read;
	char	*buf_read;

	ret_read = 1;
	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ret_read != 0)
	{
		ret_read = read(fd, buf_read, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[ret_read] = '\0';
		if (!*buf_stat)
			*buf_stat = ft_strdup("");
		*buf_stat = ft_strjoin(*buf_stat, buf_read);
		if (ft_strrchr(*buf_stat, '\n') != NULL)
			break ;
	}
	printf("\n\nhere?\n\n");
	return (buf_read);
}

char	*get_next_line(int fd)
{
	char		*cut_line;
	static char	*buf_stat;

	buf_memory_allocation(fd, &buf_stat);
	buf_cut(buf_stat);
	
	return (cut_line);
}

int main(void)
{
  int fd;
  char *line;

  fd = 0;
  fd = open("./input.txt", O_RDONLY);
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