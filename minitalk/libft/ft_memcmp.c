/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:40:47 by seokjyan          #+#    #+#             */
/*   Updated: 2023/03/23 18:32:06 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n)
	{
		if (*tmp_s1 != *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return (0);
}
