/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:53 by seokjyan          #+#    #+#             */
/*   Updated: 2023/06/30 17:40:12 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 3

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = 0;
	return (res);
}
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = 0;
	return (str);
}
int	main(void)
{
	static char	buf_stat[BUFFER_SIZE]; 
	char		*buf_read;
	char		*save;
	int			ret;
	int			fd;

	fd = open("tc.txt", O_RDONLY);
	buf_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("\n\nbuf_read\n\n");
	ret = 1;
	// while ((ret = read(fd, buf_read, BUFFER_SIZE)) != NULL)
	// {
	// 	buf_read[ret] = '\0';
	// 	printf("%s", buf_read);
	// 	free(buf_read);
	// }
	// ret = read(fd, buf_read, BUFFER_SIZE);
	save = buf_stat;
	save = ft_strdup("");
	buf_stat = ft_strjoin(save, buf_read);
	printf("\n\nbuf_stat\n\n");
	// while ((ret = read(fd, buf_stat, BUFFER_SIZE)) != NULL)
	// {
	// 	buf_stat[ret] = '\0';
	// 	printf("%s", buf_stat);
	// 	free(buf_stat);
	// }
}