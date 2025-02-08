/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:02:07 by cbauer            #+#    #+#             */
/*   Updated: 2024/11/11 16:12:29 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "./libft/libft.h"

int		ft_rvputnbr_fd(int n, int fd);
int		ft_rvputstr_fd(char *s, int fd);
int		ft_rvputchar_fd(char c, int fd);
int		ft_printf(const char *s, ...);
int		ft_putpad_fd(void *p, int fd);
int		ft_putun_fd(unsigned int n, int fd);
int		ft_puthex_fd(unsigned long long n, unsigned int base, int fd);
int		ft_puthexupcase_fd(unsigned int n, unsigned int base, int fd);

#endif