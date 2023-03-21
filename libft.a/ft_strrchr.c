/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_strrchr.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: seokjyan <seokjyan@student.42.fr>  +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2023/03/20 10:41:05 by seokjyan  #+##+# */
/*   Updated: 2023/03/20 13:55:54 by seokjyan ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if (pos != 0)
	{
		*s += pos;
		return (*s);
	}
	return (0);
}
