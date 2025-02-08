/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rvputnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:52 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 11:48:04 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rvputnbr_fd(int n, int fd)
{
	int	res;
	int	counter;

	counter = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		counter++;
	}
	if (n >= 10)
		counter += ft_rvputnbr_fd(n / 10, fd);
	res = n % 10 + '0';
	write(fd, &res, 1);
	return (++counter);
}

// int main()
// {
// 	// ft_putnbr_fd(123123, 1);
// 	ft_putnbr_fd(-2147483648, 4);
// 	return (0);
// }