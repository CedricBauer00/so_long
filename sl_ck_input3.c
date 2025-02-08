/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ck_input3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:41:19 by cbauer            #+#    #+#             */
/*   Updated: 2025/02/08 14:57:33 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_coins(t_struct *list, t_check *ck)
{
	int	i;

	i = 0;
	list->coins = (t_pos *)malloc((ck->c + 1) * sizeof(t_pos));
	if (!list->coins)
		return (-1);
	while (i < ck->c)
	{
		list->coins[i].x = 0;
		list->coins[i].y = 0;
		list->coins[i].collct = 0;
		i++;
	}
	list->coins[i].x = -1;
	list->coins[i].y = -1;
	list->coins[i].collct = -1;
	return (0);
}

void	fl_checking(t_struct *list, int x, int y, int *finish)
{
	if (x < 0 || y < 0 || y > list->rows || x > list->clm)
		return ;
	if (list->map[y][x] == '1' || list->map[y][x] == 'F')
		return ;
	if (list->map[y][x] == 'C')
	{
		list->coins[list->temp].x = x;
		list->coins[list->temp].y = y;
		list->coins[list->temp].collct = 1;
		list->temp++;
	}
	if (list->map[y][x] == 'E')
	{
		list->been_there_exit[0] = y;
		list->been_there_exit[1] = x;
		*finish = 1;
	}
	if (list->map[y][x] == '0' || list->map[y][x] == 'C'
		|| list->map[y][x] == 'E')
		list->map[y][x] = 'F';
	fl_checking(list, x + 1, y, finish);
	fl_checking(list, x - 1, y, finish);
	fl_checking(list, x, y + 1, finish);
	fl_checking(list, x, y - 1, finish);
}

int	flood_fill_check_func(t_struct *list)
{
	int	finish;
	int	i;

	i = 0;
	list->temp = 0;
	finish = 0;
	fl_checking(list, list->player.x, list->player.y, &finish);
	if (finish == 0)
		return (perror("Error\nMap is not playable!"), -1);
	while (list->coins[i].collct != -1)
	{
		if (list->coins[i].collct == 0)
			return (-1);
		if (list->coins[i].collct == 1)
			list->coins[i].collct = 0;
		i++;
	}
	return (0);
}

int	checking_for_coins(t_struct *list, int i, int j)
{
	int	k;

	k = 0;
	while (list->coins[k].collct != -1)
	{
		if (list->coins[k].x == j && list->coins[k].y == i)
		{
			list->map[i][j] = 'C';
			return (0);
		}
		k++;
	}
	return (-1);
}

void	reset_map(t_struct *list)
{
	int	i;
	int	j;

	i = -1;
	while (++i < list->rows)
	{
		j = 0;
		while (j < list->clm)
		{
			if (list->map[i][j] == 'F')
			{
				if (list->been_there_exit[0] == i
					&& list->been_there_exit[1] == j)
					list->map[i][j] = 'E';
				else if (list->player.x == j && list->player.y == i)
					list->map[i][j] = 'P';
				else
				{
					if (checking_for_coins(list, i, j) < 0)
						list->map[i][j] = '0';
				}
			}
			j++;
		}
	}
}
