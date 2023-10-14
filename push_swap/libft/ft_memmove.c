/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:50 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/02 18:10:56 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_movehelp(unsigned char *dst, unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_dst < tmp_src)
		ft_movehelp(tmp_dst, tmp_src, len);
	else
	{
		i = 0;
		while (i < len)
		{
			*(tmp_dst + len - i - 1) = *(tmp_src + len - i - 1);
			i++;
		}
	}
	return ((void *)dst);
}
