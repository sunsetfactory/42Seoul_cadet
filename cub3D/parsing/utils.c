/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:42:23 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/14 15:22:49 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(char **arr)
{
	int	row;

	row = 0;
	while (arr[row])
		free(arr[row++]);
	free(arr);
}

int	is_space(char c)
{
	if (c == 32)
		return (TRUE);
	return (FALSE);
}

int	count_line(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == '\n' || line[i + 1] == '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

char	*mk_strdup(int start, int end, char *line)
{
	char	*new_line;
	int		i;
	int		j;

	if (start > end)
		return (ft_strdup(""));
	new_line = (char *)malloc(sizeof(char) * (end - start + 2));
	if (new_line == NULL)
		exit(1);
	i = 0;
	j = start;
	while (j <= end)
	{
		if (line[j] == '\0')
			break ;
		new_line[i++] = line[j];
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}
