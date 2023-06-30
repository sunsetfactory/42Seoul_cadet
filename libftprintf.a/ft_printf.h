/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:38:48 by seokjyan          #+#    #+#             */
/*   Updated: 2023/05/15 10:53:22 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		pr_print_p(unsigned long long p, int *len, int sign);
int		pr_print_di(long long d, int *len);
int		pr_print_u(unsigned int u, int *len);
int		pr_print_x(unsigned int x, int *len);
int		pr_print_lx(unsigned int lx, int *len);
int		pr_print(char c, int *len);
int		pr_print_s(char *s, int *len);
int		pr_gatef(va_list *ap, char *format, int *len);
int		ft_printf(const char *c, ...);

#endif
