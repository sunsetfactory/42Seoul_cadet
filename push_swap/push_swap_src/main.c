/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:48:01 by seokjyan          #+#    #+#             */
/*   Updated: 2023/10/11 13:58:38 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{

	int		i;
	int		rtn;
	char	*av1;
	char	*av2;
	char	*av3;

	if (argc <= 1)
		return (0);
	else if (argc >= 2)
	{
		av2 = NULL;
		i = 1;
		while (i < argc)
		{
			av1 = ft_strjoin(argv[i++], " ");
			av3 = ft_strjoin(av2, av1);
			av2 = free_av(av1, av2, av3);
		}
		argv = ft_split(av2, ' ');
		argc = av_len(argv);
		free(av3);
	}
	rtn = push_swap(argc, argv);
	return (rtn);
}
