/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:52 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 14:52:15 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun_fd(unsigned int n, int fd)
{
	char	res;
	int		counter;

	counter = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n >= 10)
		counter += ft_putun_fd(n / 10, fd);
	res = n % 10 + '0';
	counter++;
	write(fd, &res, 1);
	return (counter);
}

// int main()
// {
// 	// ft_putnbr_fd(123123, 1);
// 	ft_putun_fd(, 1);
// 	return (0);
// }