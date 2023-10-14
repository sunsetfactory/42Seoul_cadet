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
	char	*pos;

	pos = 0;
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		pos = (char *)s;
	}
	while (*s)
	{
		if (*s == (char)c)
			pos = (char *)s;
		s++;
	}
	return (pos);
}
