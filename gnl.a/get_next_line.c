/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/07/05 23:51:12 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stat_cut(char *buf_stat, int i)
{
	char	*cut_stat;
	int		size;

	buf_stat += i;
	size = ft_strlen(buf_stat);
	cut_stat = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		*(cut_stat + i) = *(buf_stat + i);
		++i;
	}
	return (cut_stat);
}

char	*line_get(char *buf_stat, int *i)
{
	int		size;
	char	*ret_strr;
	char	*cut_line;

	ret_strr = ft_strrchr(buf_stat, '\n');
	if (ret_strr == NULL)
		size = ft_strlen(buf_stat);
	else
		size = ret_strr - buf_stat;
	cut_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!cut_line)
		return (NULL);
	cut_line[size] = '\0';
	*i = 0;
	while (*i < size)
	{
		*(cut_line + *i) = *(buf_stat + *i);
		++(*i);
	}
	return (cut_line);
}

char	*buf_memory_allocation(int fd, char *buf_stat)
{
	char	*buf_read;
	int		ret_read;
	char	*tmp_stat;

	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_read)
		return (NULL);
	if (buf_stat == NULL)
		buf_stat = ft_strdup("");
	ret_read = 1;
	while (ft_strrchr(buf_stat, '\n') == NULL && ret_read != 0)
	{
		ret_read = read(fd, buf_read, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[ret_read] = '\0';
		tmp_stat = buf_stat;
		free(buf_stat);
		buf_stat = ft_strjoin(tmp_stat, buf_read);
	}
	free(buf_read);
	return (buf_stat);
}

char	*get_next_line(int fd)
{
	char		*cut_line;
	static char	*buf_stat;
	int			i;

	if (fd < 0)
		return (NULL);
	if (ft_strrchr(buf_stat, '\n') == NULL)
		buf_stat = buf_memory_allocation(fd, buf_stat);
	cut_line = line_get(buf_stat, &i);
	buf_stat = stat_cut(buf_stat, i);
	return (cut_line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("./input.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	if (line == NULL)
		printf("%s\n", line);
	close(fd);
	return (0);
}