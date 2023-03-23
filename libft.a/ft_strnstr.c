/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:41:04 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/23 19:10:58 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	size_t	j;
	int		temp;
	if (*needle == '\0')
		return ((char *)haystack);
	j = 0;
	while (j < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			temp = 0;
			while (needle[i] != '\0')
			{
				if (haystack[i] != needle[i])
					temp = 1;
				i++;
			}
			if (temp == 0)
				return ((char *)haystack);
		}
		haystack++;
		j++;
	}
	// while (len)
	// {
	// 	if (*haystack == *needle)
	// 	{
	// 		i = 0;
	// 		while (needle[i])
	// 		{
	// 			if (haystack[i] != needle[i])
	// 				break ;
	// 			i++;
	// 		}
	// 		if (!needle[i])
	// 			return ((char *)(haystack + i));
	// 	}
	// 	haystack++;
	// 	len--;
	// }
	return (0);
}
