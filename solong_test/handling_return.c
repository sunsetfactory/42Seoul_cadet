/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:11:33 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/26 22:27:16 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init = Link screens and create identifiers (return : identifiers or NULL)
void	*init_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	return (mlx);
}

// new_window = create window and identifiers (return : identifiers or NULL)
void	*new_window_mlx(t_info info, int x, int y, char *c)
{
	void	*win;

	win = mlx_new_window(info.mlx, x, y, c);
	if (!win)
		exit(1);
	return (win);
}

// xpm_file_to_image = make image data (return : identifiers or NULL)
void	*make_image(t_info info, char *c, int *x, int *y)
{
	void	*c;

	c = mlx_xpm_file_to_image(info.mlx, c, x, y);
	if (!c)
		exit(1);
	return (c);
}
