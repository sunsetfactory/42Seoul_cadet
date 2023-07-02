/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:09 by seokjyan          #+#    #+#             */
/*   Updated: 2023/07/02 09:37:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_nl_get(char **buf_stat)
{
	int		i;
	char	*line;

	i = 0;
	while (*(*buf_stat + i) != '\n' && *(*buf_stat + i) != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
	{
		free (*buf_stat);
		return (NULL);
	}
	while (*(*buf_stat + i) != '\n' && *(*buf_stat + i) != '\0')
	{
		*(line++) = *(*buf_stat)++;
	}
	line -= i;
	if (*(*buf_stat + i) != '\n')
		(*buf_stat)++;
	// printf("\n\nline = %s\nbuf_stat = %s\n\n", line, *buf_stat);
	// printf("\n\n  get_buf_stat1 = %c\n\n", *(*buf_stat + 0));
	// printf("\n\n  get_buf_stat2 = %c\n\n", *(*buf_stat + 1));
	// printf("\n\n  get_buf_stat3 = %c\n\n", *(*buf_stat + 2));
	// printf("\n\n  get_buf_stat4 = %c\n\n", *(*buf_stat + 3));
	return (line);
}

void	gnl_nl_load(int fd, char *buf_read, char **buf_stat, int ret_read)
{
	while (ret_read != 0)
	{
		static int i = 1;
		ret_read = read(fd, buf_read, BUFFER_SIZE);
		if (*buf_read == '\0')
			printf("null\n");
		printf("read buf %d, %d : %s\n", i, ret_read, buf_read);
		i++;
		buf_read[ret_read] = '\0';
		if (!*buf_stat)
			*buf_stat = ft_strdup("");
		if (!*buf_stat)
		{
			free(buf_read);
			return ;
		}
		*buf_stat = ft_strjoin(*buf_stat, buf_read);
		if (ft_strrchr(*buf_stat, '\n') != NULL)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buf_stat;
	char		*buf_read;
	char		*cut_line;
	int			ret_read;

	if (fd < 0)
		return (NULL);
	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_read)
		return (NULL);
	ret_read = 1;
	gnl_nl_load(fd, buf_read, &buf_stat, ret_read);
	cut_line = gnl_nl_get(&buf_stat);
	// printf("\n\ncut_line = %s\nbuf_stat = %s\n\n", cut_line, buf_stat);
	return (cut_line);
}

int main(void)
{
  int fd;
//   char *line;

  fd = 0;
  fd = open("./input.txt", O_RDONLY);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
//   while ((line = get_next_line(fd)) != NULL)
//   {
//   	printf("%s", line);
// 	  free(line);
//   }
//   if (line == NULL)
// 		printf("%s\n", line);

  close(fd);

  return (0);
}