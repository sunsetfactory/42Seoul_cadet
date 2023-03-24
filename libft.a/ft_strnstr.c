/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:41:04 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/24 12:17:32 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*(haystack + i) && i + ft_strlen(needle) <= len)
	{
		if (*(haystack + i) == *needle)
		{
			if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}