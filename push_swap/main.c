/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:21:37 by seokjyan          #+#    #+#             */
/*   Updated: 2023/09/12 07:37:23 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cnt_ac(char **argv)
{
	int	cnt;

	cnt = 0;
	while (argv[cnt])
		++cnt;
	return (cnt);
}

char	**make_new_command(char *av0, char **av1)
{
	int		argc;
	int		i;
	char	**new_av;

	argc = count_av(av1);
	new_av = (char **)malloc((argc + 2) * sizeof(char *));
	if (!new_av)
		return (0);
	new_av[0] = av0;
	i = 0;
	while (i < argc)
	{
		new_av[i + 1] = av1[1];
		++i;
	}
	new_av[i] = NULL;
	return (new_av);
}

char	**split_av(char *av)
{
	char	**split_av;

	split_av = ft_split(av, ' ');
	if (!split_av)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (split_av);
}

int	main(int argc, char **argv)
{
	t_push_swap	*info;
	char		**origin_av;
	char		**new_av;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		origin_av = split_av(argv[1]);
		new_av = make_new_command(argv[0], origin_av);
		origin_av = new_av;
		argc = cnt_ac;
	}
	else
		origin_av = argv;
	info = create_info(argc, origin_av);
	info->b = NULL;
}