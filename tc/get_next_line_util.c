/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:03:07 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/30 11:18:08 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	i = 0;
	len = 0;
	while (*(s1 + i))
		*(p + len++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i))
		*(p + len++) = *(s2 + i++);
	*(p + len) = '\0';
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (s);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(p + i) = *(s + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}