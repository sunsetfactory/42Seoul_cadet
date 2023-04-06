/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:50:26 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/06 23:17:30 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		count += *s != '\0';
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_malloc_strs(char *s, char c)
{
	char	*tmp;
	int		out_i;

	out_i = 0;
	while (*(s + out_i) && *(s + out_i) != c)
		out_i++;
	tmp = (char *)malloc(sizeof(char) * (out_i + 1));
	if (!tmp)
		return (NULL);
	out_i = 0;
	while (*(s + out_i) && *(s + out_i) != c)
	{
		*(tmp + out_i) = *(s + out_i);
		out_i++;
	}
	*(tmp + out_i) = 0;
	return (tmp);
}

static void	*words_free(char **words, int i)
{
	while (i >= 0)
	{
		free(*(words + i));
		--i;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*cp_s;
	int		i;

	cp_s = (char *)s;
	words = (char **)malloc(sizeof(char *) * (ft_word_count(cp_s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*(cp_s))
	{
		while (*cp_s && *cp_s == c)
			cp_s++;
		if (*cp_s && *cp_s != c)
		{
			*(words + i) = ft_malloc_strs(cp_s, c);
			if (!*(words + i))
				return (words_free(words, i));
			while (*cp_s && *cp_s != c)
				cp_s++;
			i++;
		}
	}
	*(words + i) = 0;
	return (words);
}
