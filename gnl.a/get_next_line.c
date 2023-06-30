/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/30 17:45:33 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_nl_check(int fd, char *buf_read, char *buf_stat, int ret_read)
{
	char	*save;

	while (ret_read != 0)
	{
		ret_read = read(fd, buf_read, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buf_stat);
			return (NULL);
		}
		buf_read[ret_read] = '\0';
		save = buf_stat;
		if (!save)
			save = ft_strdup("");
		buf_stat = ft_strjoin(save, buf_read);
		if (!buf_stat)
		{
			free(save);
			return (NULL);
		}
		free(save);
		if (ft_strrchr(buf_stat, '\n') != NULL)
			break ;
	}
	return (buf_stat);
}

char	*get_next_line(int fd)
{
	static char	*buf_stat;
	char		*buf_read;
	char		*ret_line;
	int			ret_read;

	if (fd < 0)
		return (NULL);
	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_read)
		return (NULL);
	ret_read = 1;
	buf_stat = gnl_nl_check(fd, buf_read, buf_stat, ret_read);
	return (ret_line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

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