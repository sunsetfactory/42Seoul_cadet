/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/07/18 17:11:37 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*cut_line;
	static char	*buf_static = "";
	int			size;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (buf_static == NULL)
		return (NULL);
	if (ft_strchr(buf_static, '\n', &size) == NULL)
		buf_static = buf_memory_allocation(fd, buf_static);
	cut_line = line_get(buf_static, size);
	if (cut_line == NULL)
	{
		free(buf_static);
		buf_static = NULL;
	}
	else
	{
		buf_static = stat_cut(buf_static, size);
		if (buf_static == NULL)
		{
			free(buf_static);
			buf_static = NULL;
		}
	}
}