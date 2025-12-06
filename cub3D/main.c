/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:30:10 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/29 15:56:33 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *txt)
{
	write(2, "Error\n", 6);
	while (*txt)
		write(2, txt++, 1);
	write(2, "\n", 1);
	exit(1);
}

int	normal_exit(void)
{
	ft_putstr_fd("--------------------\n", 1);
	ft_putstr_fd("  game termination\n", 1);
	ft_putstr_fd("--------------------\n", 1);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*param;
	t_img	img;

	if (argc != 2)
		ft_exit("Error in number of factors");
	param = malloc(sizeof(t_param));
	param->rc = malloc(sizeof(t_rc));
	param->mlx = malloc(sizeof(t_mlx));
	param->img = &img;
	init_param(param);
	param->map_file_name = argv[1];
	parse(param);
	init_mlx(param);
	mlx_hook(param->mlx->win, KEYPRESS, 1L << 0, key_hook, param);
	mlx_hook(param->mlx->win, KEY_RED, 0, &normal_exit, param);
	param->img->img = mlx_new_image(param->mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	param->img->addr = mlx_get_data_addr(param->img->img, \
		&param->img->bpp, &param->img->len, &param->img->endian);
	mlx_loop_hook(param->mlx->mlx, main_loop, param);
	mlx_loop(param->mlx->mlx);
	return (0);
}
