/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorras- <jmorras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:15:52 by jmorras-          #+#    #+#             */
/*   Updated: 2022/03/17 16:48:04 by jmorras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printf_args(char *str, va_list ptr);
int		var_s(char *var);
int		var_n(long long var);
int		var_x(unsigned int var, char uplow);
int		var_p(unsigned long var);
void	ft_putnbr(long long n);
void	ft_puthex(unsigned long long n, char uplow );
void	ft_putchar_fd(char c, int fd);

#endif
