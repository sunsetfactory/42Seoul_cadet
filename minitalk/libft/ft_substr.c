/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:23:41 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/06 22:06:34 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	size_t			s_len;
	size_t			size;

	s_len = ft_strlen(s);
	size = len;
	if (s_len < start)
		size = 0;
	else if (s_len - start < len)
		size = s_len - start;
	sub = (char *)malloc(size + 1);
	if (!sub)
		return (0);
	i = 0;
	while (s_len >= start && i < len && *(s + i + start))
	{
		*(sub + i) = *(s + i + start);
		i++;
	}
	*(sub + i) = 0;
	return (sub);
}
