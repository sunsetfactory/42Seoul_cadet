#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int 	len;
	int		i;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		*(res + i) = f(i, *(s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
