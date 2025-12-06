/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:46:04 by seokjyan          #+#    #+#             */
/*   Updated: 2024/01/20 16:36:31 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_envp(t_envp *my_envp, char **envp, int i_line)
{
	int	i_word;

	if (ft_strrchr(envp[i_line], (int) '=') == NULL)
	{
		my_envp->key = ft_strdup(envp[i_line]);
		my_envp->value = "";
		my_envp->state = NO_EQUAL;
	}
	else
	{
		i_word = 0;
		while (envp[i_line][i_word] != '\0' && envp[i_line][i_word] != '=')
			i_word++;
		my_envp->key = ft_substr(envp[i_line], 0, i_word);
		my_envp->value = ft_strdup(envp[i_line] + i_word + 1);
		my_envp->state = HAS_EQUAL;
	}
}

t_env_d	*set_my_envp(void)
{
	t_env_d	*my_envp;

	my_envp = (t_env_d *)malloc(sizeof(t_env_d));
	my_envp->data = (t_envp *)malloc(sizeof(t_envp));
	my_envp->head = (t_envp *)malloc(sizeof(t_envp));
	my_envp->tail = NULL;
	my_envp->head->key = ft_strdup("?");
	my_envp->head->state = 0;
	return (my_envp);
}

t_envp	*create_next_pointer(char **envp, int i_line)
{
	t_envp	*next;

	if (envp[i_line] != NULL)
		next = (t_envp *)malloc(sizeof(t_envp));
	else
		next = NULL;
	return (next);
}

t_env_d	*make_envp(char **envp)
{
	t_env_d	*my_envp;
	t_envp	*head_data;
	int		i_line;

	my_envp = set_my_envp();
	head_data = my_envp->data;
	i_line = 0;
	while (envp[i_line] != NULL)
	{
		add_envp(my_envp->data, envp, i_line);
		i_line++;
		my_envp->data->next = create_next_pointer(envp, i_line);
		if (my_envp->tail == NULL)
		{
			my_envp->head->next = my_envp->data;
			my_envp->tail = my_envp->data;
		}
		else
			my_envp->tail = my_envp->data;
		my_envp->data = my_envp->data->next;
	}
	my_envp->data = head_data;
	return (my_envp);
}

// t_envp	*make_envp(char **envp)
// {
// 	t_envp	*my_envp;
//     t_envp  *my_envp_head;
// 	int		i_line;
// 	int		i_word;

// 	my_envp = (t_envp *)malloc(sizeof(t_envp));
//     my_envp_head = my_envp;
// 	i_line = 0;
// 	while (envp[i_line] != NULL)
// 	{
// 		if (ft_strrchr(envp[i_line], (int)'=') == NULL)
// 		{
// 			my_envp->key = ft_strdup(envp[i_line]);
// 			my_envp->value = "";
// 			my_envp->state = NO_EQUAL;
// 		}
// 		else
// 		{
// 			i_word = 0;
// 			while (envp[i_line][i_word] != '\0' && envp[i_line][i_word] != '=')
// 				i_word++;
// 			my_envp->key = ft_substr(envp[i_line], 0, i_word);
// 			my_envp->value = ft_strdup(envp[i_line] + i_word + 1);
// 			my_envp->state = HAS_EQUAL;
// 		}
//         i_line++;
// 		if (envp[i_line] != NULL)
// 			my_envp->next = (t_envp *)malloc(sizeof(t_envp));
// 		else
// 			my_envp->next = NULL;
// 		my_envp = my_envp->next;
// 	}
// 	return (my_envp_head);
// }
