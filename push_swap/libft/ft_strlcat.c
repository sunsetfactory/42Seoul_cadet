/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:58 by seokjyan          #+#    #+#             */
/*   Updated: 2023/04/02 21:51:53 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst += dst_len;
	if (dstsize < dst_len)
		return (src_len + dstsize);
	dstsize -= dst_len;
	while (*src && 1 < dstsize--)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
