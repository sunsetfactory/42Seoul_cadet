/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:24:54 by seokjyan          #+#    #+#             */
/*   Updated: 2023/11/03 13:41:33 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_filename(t_game *game, char *filename)
{
	int	f_len;
	int	e_len;

	f_len = ft_strlen(filename);
	e_len = ft_strlen(FILE_NAME_EXTENSION);
	if (ft_strncmp(&filename[f_len - e_len], FILE_NAME_EXTENSION, e_len))
		error_exit(game, "wrong extension name\n");
}
