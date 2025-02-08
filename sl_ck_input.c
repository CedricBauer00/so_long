/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ck_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:37:18 by cbauer            #+#    #+#             */
/*   Updated: 2025/02/08 14:56:56 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *str, char *src)
{
	int	i;

	i = 0;
	if (str == NULL || src == NULL)
		return (-1);
	while (str[i] && src[i] && str[i] == src[i])
		i++;
	return (str[i] - src[i]);
}

int	checking_name(char **argv)
{
	char	*str;
	int		i;

	i = 0;
	str = ".ber";
	if (!argv[1])
		return (perror("Error\nPlease enter a map!"), -1);
	while (argv[1][i])
		i++;
	if (i < 5)
		return (perror("Error\nPlease enter a valid map! Too short!"), -1);
	if (ft_strcmp(&argv[1][i - 4], str) == 0)
		return (0);
	return (perror("Error\nPlease enter a .ber file!"), -1);
}

int	open_func2(t_struct *list, int fd)
{
	char	*str;
	int		temp;

	str = get_next_line(fd);
	while (str != NULL)
	{
		temp = ft_strlen(str);
		if (str[temp - 1] == '\n')
			temp -= 1;
		if (list->clm == 0)
			list->clm = temp;
		if (temp != list->clm)
			return (free(str), -1);
		list->rows++;
		free(str);
		str = get_next_line(fd);
	}
	list->map = (char **)malloc(list->rows * sizeof(char *));
	if (!list->map)
		return (perror("Error\nFailed to allocate map!"), -1);
	return (0);
}

int	open_func(t_struct *list)
{
	int	fd;

	fd = open(list->argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\nNot able to open file!"), -1);
	if (open_func2(list, fd) < 0)
		return (-1);
	close(fd);
	if (open_func3(list) < 0)
		return (-1);
	return (0);
}

int	checking_input(t_struct *list, char **argv)
{
	list->argv = argv;
	if (checking_name(argv) < 0)
		return (-1);
	if (open_func(list) < 0)
		return (-1);
	if (valid_char(list) < 0)
		return (-1);
	if (valid_border(list) < 0)
		return (-1);
	if (valid_extras(list) < 0)
		return (-1);
	if (flood_fill_check_func(list) < 0)
		return (-1);
	reset_map(list);
	return (0);
}
