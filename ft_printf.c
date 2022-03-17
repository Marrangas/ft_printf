/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorras- <jmorras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:36:55 by jmorras-          #+#    #+#             */
/*   Updated: 2022/03/17 16:52:13 by jmorras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Funct 5
int	var_n(long long var)
{
	int	n_char;

	var = (long long) var;
	n_char = 0;
	ft_putnbr(var);
	if (var == 0)
		return (1);
	if (var < 0)
	{
		var = var * (-1);
		n_char = 1;
	}
	while (var != 0)
	{
		var = var / 10;
		n_char++;
	}
	return (n_char);
}

// funct 4
int	var_x(unsigned int var, char uplow)
{
	int	n_char;

	n_char = 0;
	if (var == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_puthex(var, uplow);
	while (var != 0)
	{
		var = var / 16;
		n_char++;
	}
	return (n_char);
}

//funct 3
int	var_p(unsigned long var)
{
	int	n_char;

	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (var == 0)
	{
		write (1, "0", 1);
		return (3);
	}
	n_char = 2;
	ft_puthex(var, 'x');
	while (var != 0)
	{
		var = var / 16;
		n_char++;
	}
	return (n_char);
}

//Function 2
int	ft_printf_args(char *str, va_list ptr)
{
	if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (*str == 'c')
	{
		ft_putchar_fd((char) va_arg(ptr, int), 1);
		return (1);
	}
	if (*str == 's' )
		return (var_s(va_arg(ptr, char *)));
	if (*str == 'd' || *str == 'i')
		return (var_n(va_arg(ptr, int)));
	if (*str == 'u')
		return (var_n(va_arg(ptr, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (var_x(va_arg(ptr, unsigned int), *str));
	if (*str == 'p')
		return (var_p(va_arg(ptr, unsigned long)));
	return (-1);
}

// Function 1
int	ft_printf(const char *str, ...)
{
	int		prints;
	va_list	ptr;
	int		i;

	if (!str)
		return (0);
	va_start (ptr, str);
	i = 0;
	prints = 0;
	while (str[i])
	{
		if (str[i] == '%')
			prints += ft_printf_args((char *) str + i++ + 1, ptr);
		else
		{
			write (1, &str[i], 1);
			prints++;
		}
		i++;
	}
	va_end (ptr);
	return (prints);
}
/*
// - DEBUGGING - //
#include <stdio.h>
int	main (void)
{
	char c= 'a';
	int d = 234;
	int i = 234;
	unsigned int u = 2977234934;
	char str[] = "\'ESTO ES UNA CAENA\'%";

	ft_printf("puedo imprimir un %%");
	ft_printf("también puede ser una cosita chiquita como un char: %c \n", c);
	ft_printf("puedo imprimir más larga como una str: %s \n", str);
	ft_printf("puede ser un decimimal: %d igual que un int: %i \n" , d, i);
	ft_printf("también unsigned  %u, y el eterno poder del putnbr \n", u, i);
	ft_printf("puedo imprimir este unsigned como hexadecimal: %x \n", u);
	ft_printf("o en mayúscua porque soy mas chulo que mi pirulo: %X \n", u);
	ft_printf(" esto es una dirección de memoria %p \n", &str[2]);
	ft_printf("\n");
	ft_printf("Ahora solo queda hacer puerbas raras... chan chan chan!!!!!");
	printf("------------------------------------");
	printf("Checker de la función original %% \n");
	printf("------------------------------------");
	printf("Checker de la función original %c \n", c);
	printf("-----------------------------------------");
	printf("Checker de la función original %s \n", str);
	printf("---------------------------------------");
	printf("Checker de la función original %d \n", d);
	printf("---------------------------------------");
	printf("Checker de la función original %i \n", i);
	printf("---------------------------------------");
	printf("Checker de la función original %u \n", u);
	printf("---------------------------------------");
	printf("Checker de la función original %x \n", u);
	printf("---------------------------------------");
	printf("Checker de la función original %X \n", u);
	printf("---------------------------------------------");
	printf("Checker de la función original %p \n", NULL);
	printf("---------------------------------------------");
	printf("Checker de la función original \n");
	printf("%d", -154);
	return (0);
}
*/