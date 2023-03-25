/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:48 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/24 18:41:42 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dst && !src)
		return (dst);
	tmp_d = (unsigned char *)dst;
	tmp_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(tmp_d + i) = *(tmp_s + i);
		i++;
	}
	return (dst);
}
