/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:45:28 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 14:59:32 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpad_fd(void *p, int fd)
{
	unsigned int	counter;
	uintptr_t		n;

	if (p == NULL)
	{
		write (fd, "0x0", 3);
		return (3);
	}
	n = (uintptr_t)p;
	write(fd, "0x", 2);
	counter = ft_puthex_fd(n, 16, fd);
	return (counter + 2);
}
