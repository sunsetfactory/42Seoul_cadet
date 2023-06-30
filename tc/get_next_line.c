/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/30 11:20:23 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *bp)
{
	int		i;
	int		n;
	char	*line;

	i = 0;
	if (*bp == '\0')
		return (NULL);
	n = 0;
	while (*(bp + n) != '\n' && *(bp + n) != '\0')
		n++;
	line = (char *)malloc(sizeof(char) * n + 2);
	if (!line)
	{
		free(bp);
		return (NULL);
	}
	while (*(bp + i) != '\0' && *(bp + i) != '\n')
	{
		*(line + i) = *(bp + i);
		i++;
	}
	if (*(bp + i) == '\n')
		*(line + i++) = '\n';
	*(line + i) = '\0';
	return (line);
}

char	*ft_get_backup(char *bp)
{
	int		n;
	int		len;
	char	*new;

	n = 0;
	while (*(bp + n) != '\n' && *(bp + n) != '\0')
		n++;
	if (*(bp + n) == '\0')
	{
		free(bp);
		return (NULL);
	}
	len = ft_strlen(bp);
	new = (char *)malloc(sizeof(char) * (len - n + 1));
	if (!new)
	{
		free(bp);
		return (NULL);
	}
	len = 0;
	while (*(bp + ++n) != '\0')
		*(new + len++) = *(bp + n);
	*(new + len) = '\0';
	free(bp);
	return (new);
}

char	*ft_read_file(int fd, char *backup, char *buf, int n)
{
	char	*prev;

	while (n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(backup);
			return (NULL);
		}
		buf[n] = '\0';
		prev = backup;
		if (!prev)
			prev = ft_strdup("");
		backup = ft_strjoin(prev, buf);
		if (!backup)
		{
			free(prev);
			return (NULL);
		}
		free(prev);
		if (ft_strchr(backup, '\n') != NULL)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;
	size_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	backup = ft_read_file(fd, backup, buf, n);
	free(buf);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_get_backup(backup);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

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