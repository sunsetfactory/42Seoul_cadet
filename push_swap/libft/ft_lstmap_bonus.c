/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:54:20 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/06 19:16:38 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tmp;
	void	*maybe;

	if (!lst)
		return (0);
	map = 0;
	while (lst)
	{
		maybe = f(lst->content);
		tmp = ft_lstnew(maybe);
		if (!tmp)
		{
			free(maybe);
			ft_lstclear(&map, del);
			return (0);
		}
		ft_lstadd_back(&map, tmp);
		lst = lst->next;
	}
	tmp->next = 0;
	return (map);
}
