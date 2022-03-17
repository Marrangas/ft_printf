/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorras- <jmorras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:29:46 by jmorras-          #+#    #+#             */
/*   Updated: 2022/03/17 16:51:28 by jmorras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// funct 9
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// Funct 8
void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
		ft_putnbr(n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}

// Funct 7
void	ft_puthex(unsigned long long n, char uplow )
{
	if (n >= 16)
		ft_puthex(n / 16, uplow);
	if (uplow == 'X')
		uplow = 0;
	else if (uplow == 'x')
		uplow = 32;
	n = n % 16;
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd(n + 55 + uplow, 1);
}

// Funct 6
int	var_s(char *var)
{
	int	i;

	i = 0;
	if (var == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}	
	while (var[i])
	{
		ft_putchar_fd(var[i], 1);
		i++;
	}
	return (i);
}
