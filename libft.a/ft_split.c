/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:50:26 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/31 13:58:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_word_count(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*ft_malloc_strs(char *s, char c)
{
	char	*tmp;
	int		out_i;

	out_i = 0;
	while (*(s + out_i) && *(s + out_i) != c)
		out_i++;
	tmp = (char *)malloc(sizeof(char) * (out_i + 1));
	out_i = 0;
	while (*(s + out_i) && *(s + out_i) != c)
	{
		*(tmp + out_i) = *(s + out_i);
		out_i++;
	}
	*(tmp + out_i) = 0;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*cp_s;
	int		i;

	cp_s = (char *)s;
	words = (char **)malloc(sizeof(char *) * (ft_word_count(cp_s, c) + 1));
	if (!words)
		return (0);
	i = 0;
	while (*(cp_s))
	{
		while (*cp_s && *cp_s == c)
			cp_s++;
		if (*cp_s && *cp_s != c)
		{
			*(words + i) = ft_malloc_strs(cp_s, c);
			while (*cp_s && *cp_s != c)
				cp_s++;
			i++;
		}
	}
	*(words + i) = 0;
	return (words);
}
