/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:52 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/05 16:20:08 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned long long n, unsigned int base, int fd)
{
	char				res;
	unsigned long long	remainder;
	unsigned int		counter;

	counter = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n >= base)
		counter += ft_puthex_fd(n / base, base, fd);
	remainder = n % base;
	if (remainder <= 9)
		res = remainder + '0';
	else
		res = remainder + 'a' - 10;
	write(fd, &res, 1);
	counter++;
	return (counter);
}

// int main()
// {
// 	// ft_put_fd(123123, 1);
// 	ft_puthex_fd(42, 16, 0);
// 	return (0);
// }