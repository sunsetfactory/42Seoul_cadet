/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:50 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/21 16:51:21 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		tmp_dst;
	const unsigned char	tmp_src;
	size_t				i;

	tmp_dst = (unsigned char)dst;
	tmp_src = (const unsigned char)src;
	if (tmp_dst > tmp_src)
	{
		i = 0;
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		len--;
		while (len)
		{
			tmp_dst[len] = tmp_src[len];
			len--;
		}
	}	
	return (dst);
}
