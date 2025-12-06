/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:36:11 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/25 19:48:59 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	allocate_and_set(int map_width, char **map, int *row)
{
	map[(*row)] = malloc(sizeof(char) * (map_width + 1) + 1);
	if (!map[(*row)])
		ft_exit("Allocate error!");
	ft_memset(map[(*row)], ' ', map_width + 1);
	map[(*row)][map_width + 1] = '\0';
	(*row) += 1;
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < n && src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}

void	init_idx(t_idx *idx, char *line)
{
	if (count_line(line) < 1)
		ft_exit("No map");
	idx->i = 0;
	idx->start = 0;
	idx->row = 0;
}

char	**mk_split(char *line, int map_width)
{
	char	**map;
	int		line_length;
	t_idx	idx;

	init_idx(&idx, line);
	map = malloc(sizeof(char *) * (count_line(line) + 3));
	if (!map)
		ft_exit("Allocate error!");
	allocate_and_set(map_width, map, &idx.row);
	while (line[idx.i])
	{
		if (line[idx.i] == '\n' || line[idx.i + 1] == '\0')
		{
			line_length = idx.i - idx.start;
			if (line[idx.i] != '\n' && line[idx.i + 1] == '\0')
				line_length++;
			allocate_and_set(map_width, map, &idx.row);
			ft_strncpy(map[idx.row - 1], line + idx.start, line_length);
			idx.start = idx.i + 1;
		}
		idx.i++;
	}
	allocate_and_set(map_width, map, &idx.row);
	map[idx.row] = NULL;
	return (map);
}
