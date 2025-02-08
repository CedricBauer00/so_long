/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rvputstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:01:51 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 14:52:28 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rvputstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	return (counter);
}

// int main()
// {
// 	ft_putstr_fd("", 1);
// 	return (0);
// }