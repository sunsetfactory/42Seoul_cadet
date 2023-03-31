#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tmp;

	if (!lst)
		return (0);
	map = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&map, del);
			return (0);
		}
		ft_lstadd_back(&map, tmp);
		lst = lst->next;
	}
	tmp->next = 0;
	return (map);
}
