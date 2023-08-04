/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/07/19 01:30:25 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stat_cut(t_storage *buf_stat, int i)
{
	char	*cut_stat;
	int		size;
	char	*temp;

	temp = buf_stat->content;
	buf_stat->content += i;
	size = ft_strlen(buf_stat->content);
	cut_stat = (char *)malloc(sizeof(char) * (size + 1));
	if (!cut_stat)
	{
		buf_stat->err = 1;
		return (NULL);
	}
	cut_stat[size] = '\0';
	i = 0;
	while (i < size)
	{
		*(cut_stat + i) = *(buf_stat->content + i);
		++i;
	}
	free(temp);
	temp = NULL;
	return (cut_stat);
}

char	*line_get(t_storage *buf_stat, int *i)
{
	int		size;
	char	*ret_strr;
	char	*cut_line;

	if (*buf_stat->content == '\0')
		return (NULL);
	ret_strr = ft_strchr(buf_stat->content, '\n');
	if (ret_strr == NULL)
		size = ft_strlen(buf_stat->content);
	else
		size = ret_strr - buf_stat->content + 1;
	cut_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!cut_line)
	{
		buf_stat->err = 1;
		return (NULL);
	}
	cut_line[size] = '\0';
	*i = 0;
	while (*i < size)
	{
		*(cut_line + *i) = *(buf_stat->content + *i);
		++(*i);
	}
	return (cut_line);
}

char	*buf_memory_allocation(int fd, t_storage *buf_stat)
{
	char	buf_read[BUFFER_SIZE + 1];
	int		ret_read;
	char	*tmp_stat;

	if (buf_stat->content == NULL)
	{
		buf_stat->content = ft_strdup("");
		buf_stat->err = 0;
	}
	ret_read = 1;
	while (ft_strchr(buf_stat->content, '\n') == NULL && ret_read != 0)
	{
		ret_read = read(fd, buf_read, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buf_stat->content);
			return (NULL);
		}
		buf_read[ret_read] = '\0';
		tmp_stat = buf_stat->content;
		buf_stat->content = ft_strjoin(tmp_stat, buf_read);
		free(tmp_stat);
		tmp_stat = NULL;
	}
	return (buf_stat->content);
}

char	*get_next_line(int fd)
{
	char				*cut_line;
	static t_storage	buf_stat;
	int					i;

	if (fd < 0 || fd > OEPN_MAX || BUFFER_SIZE <= 0 || \
	BUFFER_SIZE > 18446744073709551615UL)
		return (NULL);
	if (buf_stat.err == 1)
		return (NULL);
	if (ft_strchr(buf_stat.content, '\n') == NULL)
		buf_stat.content = buf_memory_allocation(fd, &buf_stat);
	if (buf_stat.content == NULL)
		return (NULL);
	cut_line = line_get(&buf_stat, &i);
	if (cut_line == NULL)
	{
		free(buf_stat.content);
		buf_stat.content = NULL;
	}
	else
		buf_stat.content = stat_cut(&buf_stat, i);
	return (cut_line);
}
