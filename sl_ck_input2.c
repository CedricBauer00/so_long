/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ck_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:30:34 by cbauer            #+#    #+#             */
/*   Updated: 2025/02/08 14:57:26 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*grid_func(t_struct *list, char *temp)
{
	int		i;
	char	*temp2;

	i = 0;
	temp2 = (char *)malloc(list->clm * sizeof(char));
	if (!temp2)
		return (NULL);
	while (i < list->clm)
	{
		temp2[i] = temp[i];
		i++;
	}
	return (temp2);
}

int	open_func3(t_struct *list)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(list->argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\nNot able to open file!"), -1);
	while (i < list->rows)
	{
		temp = get_next_line(fd);
		list->map[i] = grid_func(list, temp);
		if (list->map[i] == NULL)
			return (perror("Error\nMap content is invalid!"), -1);
		free(temp);
		i++;
	}
	close(fd);
	return (0);
}

int	valid_char(t_struct *list)
{
	int	i;
	int	j;

	j = 0;
	while (j < list->rows)
	{
		i = 0;
		while (i < list->clm && (list->map[j][i] == '0'
			|| list->map[j][i] == '1' || list->map[j][i] == 'P'
			|| list->map[j][i] == 'C' || list->map[j][i] == 'E'))
		{
			if (list->map[j][i] == 'P')
			{
				list->player.x = i;
				list->player.y = j;
			}
			i++;
		}
		if (i != list->clm)
			return (perror("Error\nMap is missing essential components!1"), -1);
		j++;
	}
	return (0);
}

int	valid_border(t_struct *list)
{
	int	i;
	int	j;

	j = 0;
	while (j < list->rows)
	{
		i = 0;
		while (i < list->clm)
		{
			if (list->map[0][i] != '1' || list->map[list->rows - 1][i] != '1')
				return (perror("Error\nBorders are invalid!"), -1);
			i++;
		}
		if (list->map[j][0] != '1' || list->map[j][list->clm - 1] != '1')
			return (perror("Error\nBorders are invalid!"), -1);
		j++;
	}
	return (0);
}

int	valid_extras(t_struct *list)
{
	int		i;
	int		j;
	t_check	ck;

	j = 0;
	set_default(list, &ck, 1);
	while (j < list->rows)
	{
		i = -1;
		while (++i < list->clm)
		{
			if (list->map[j][i] == 'P')
				ck.p++;
			if (list->map[j][i] == 'E')
				ck.e++;
			if (list->map[j][i] == 'C')
				ck.c++;
		}
		j++;
	}
	if (ck.p != 1 || ck.e != 1 || ck.c < 1)
		return (perror("Error\nMap is missing essential components!2"), -1);
	if (init_coins(list, &ck) < 0)
		return (perror("Error\nInitialyzing coins failed!"), -1);
	return (0);
}
