/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:18:50 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/20 20:37:18 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_map(t_param *param, int fd, char **line)
{
	int		flag;
	char	*buf;
	char	*temp;

	flag = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		if (check_type(buf) == FALSE)
			flag = TRUE;
		if (flag == TRUE)
		{
			temp = *line;
			*line = ft_strjoin(*line, buf);
			free(temp);
			if (!(*line))
				ft_exit("Allocate error");
			if (param->map_width < (int)ft_strlen(buf))
				param->map_width = (int)ft_strlen(buf);
		}
		free(buf);
	}
}

void	copy_map(t_param *param)
{
	int		fd;
	char	*line;

	fd = open(param->map_file_name, O_RDONLY);
	if (fd < 0)
		ft_exit("Invalid file");
	line = ft_strdup("");
	if (!line)
		ft_exit("Allocate error");
	read_map(param, fd, &line);
	close(fd);
	param->world_map = mk_split(line, param->map_width);
	param->map_height = count_line(line);
	free(line);
}

char	*read_line(int fd)
{
	char	*buf;
	char	*line;
	char	*temp;

	line = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		temp = line;
		line = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
		if (!line)
			ft_exit("Allocate error");
	}
	return (line);
}

void	file_parsing(t_param *param)
{
	int		fd;
	char	*line;

	fd = open(param->map_file_name, O_RDONLY);
	if (fd < 0)
		ft_exit("Invalid file");
	line = read_line(fd);
	close(fd);
	if (line[0] == '\0')
		ft_exit("Empty file");
	find_path_and_color(line, param);
	copy_map(param);
	free(line);
}
