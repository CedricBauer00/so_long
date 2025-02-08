/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rvputchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:21 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 14:58:56 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rvputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

// int main()
// {
// 	ft_putchar_fd('c', 0);
// 	return (0);
// }