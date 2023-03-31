#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;
	
	if (lst)
	{
		ft_lstlast(*lst);
		tmp = *lst;
		tmp->next = new;
	}
}
