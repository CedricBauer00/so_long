/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:03:39 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 16:27:04 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_printformat(const char *s, va_list args, int c)
{
	int	printed;

	printed = 0;
	if (s[c] == 'c')
		printed += ft_rvputchar_fd(va_arg(args, int), 1);
	else if (s[c] == 's')
		printed += ft_rvputstr_fd(va_arg(args, char *), 1);
	else if (s[c] == 'd')
		printed += ft_rvputnbr_fd(va_arg(args, int), 1);
	else if (s[c] == 'p')
		printed += ft_putpad_fd(va_arg(args, void *), 1);
	else if (s[c] == 'i')
		printed += ft_rvputnbr_fd(va_arg(args, int), 1);
	else if (s[c] == 'u')
		printed += ft_putun_fd(va_arg(args, unsigned int), 1);
	else if (s[c] == 'x')
		printed += ft_puthex_fd(va_arg(args, unsigned int), 16, 1);
	else if (s[c] == 'X')
		printed += ft_puthexupcase_fd(va_arg(args, int), 16, 1);
	else if (s[c] == '%')
		printed += ft_rvputchar_fd('%', 1);
	else
		return (-1);
	return (printed);
}

int	ft_printf(const char *s, ...)
{
	int		c;
	int		printed;
	va_list	args;

	va_start(args, s);
	c = 0;
	printed = 0;
	while (s[c])
	{
		if (s[c] == '%')
		{
			c++;
			printed += ft_printformat(s, args, c);
			c++;
		}
		else
		{
			printed += ft_rvputchar_fd(s[c], 1);
			c++;
		}
	}
	va_end(args);
	return (printed);
}

// #include <stdio.h>
// int main()
// {
// 	char	*p;
// 	p = "Hello";
// 	ft_printf("%x\n", 255);
// 	ft_printf("%X\n", 255);
// 	ft_printf("%p\n", "");
// 	printf("original : %x", 123123);
// 	return (0);
// }

// // int main()
// {
// 	char c = 'E';
// 	printf("%c", c);
// 	return (0);
// }