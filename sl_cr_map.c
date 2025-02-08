/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cr_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:41:18 by cbauer            #+#    #+#             */
/*   Updated: 2025/02/08 14:51:52 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_coins_helper(t_struct *list, int i, int j)
{
	while (1)
	{
		if (list->coins[i].x * list->size == \
			list->images.imgcoin->instances[j].x
			&& list->coins[i].y * list->size == \
			list->images.imgcoin->instances[j].y)
		{
			list->images.imgcoin->instances[j].enabled = false;
			break ;
		}
		j++;
	}
}

void	collect_coins(void	*ptr)
{
	t_struct	*list;
	int			i;
	int			inst;

	list = (t_struct *)ptr;
	inst = list->player.i;
	i = 0;
	while (list->coins[i].collct != -1)
	{
		if (list->images.imgplr->instances[inst].x == \
			list->coins[i].x * list->size
			&& list->images.imgplr->instances[inst].y == \
			list->coins[i].y * list->size)
		{
			if (list->coins[i].collct != 1)
			{
				list->coins[i].collct = 1;
				collect_coins_helper(list, i, 0);
			}
		}
		i++;
	}
}

void	move_player_helper(t_struct *list, int t_x, int t_y, int indic)
{
	int	i;
	int	x;
	int	y;

	y = t_y * list->size;
	x = t_x * list->size;
	if (indic == 0)
	{
		i = list->player.i;
		list->images.imgplr->instances[i].enabled = false;
		return ;
	}
	i = 0;
	while (indic == 1)
	{
		if (list->images.imgplr->instances[i].x == x
			&& list->images.imgplr->instances[i].y == y)
		{
			list->images.imgplr->instances[i].enabled = true;
			list->player.i = i;
			break ;
		}
		i++;
	}
}

void	key_close(t_struct *list)
{
	int	i;
	int	inst;

	inst = list->player.i;
	i = 0;
	if (mlx_is_key_down(list->mlx.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(list->mlx.mlx);
	if (list->images.imgplr->instances[inst].y == \
		list->been_there_exit[0] * list->size
		&& list->images.imgplr->instances[inst].x == \
		list->been_there_exit[1] * list->size)
	{
		while (1)
		{
			if (list->coins[i].collct == 0)
				break ;
			else if (list->coins[i].collct == -1)
			{
				mlx_close_window(list->mlx.mlx);
				break ;
			}
			i++;
		}
	}
}

void	move_player(t_struct *list, int p_x, int p_y, int indic)
{
	static int	x = 0;
	static int	y = 0;
	int			k;

	k = 0;
	if (indic == 0)
		x = p_x;
	if (indic == 0)
		y = p_y;
	if (indic != 0)
	{
		if (list->map[y + p_y][x + p_x] != '1')
		{
			while (k <= 150000000)
				k++;
			move_player_helper(list, x, y, 0);
			x += p_x;
			y += p_y;
			move_player_helper(list, x, y, 1);
			list->moves++;
			ft_printf("%d\n", list->moves);
		}
	}
}

void	key(t_struct *list, int updown, int lr)
{
	int	x;
	int	y;
	int	ls;

	ls = list->size;
	y = list->images.imgplr->instances[list->player.i].y;
	x = list->images.imgplr->instances[list->player.i].x;
	if (lr == 0 && updown == 1 && list->map[(y - 1) / ls][x / ls] != '1' \
		&& list->map[(y - 1) / ls][(x + ls - 1) / ls] != '1')
		move_player(list, 0, -1, 1);
	if (lr == 0 && updown == 2 && list->map[(y + ls) / ls][x / ls] != '1' \
		&& list->map[(y + ls) / ls][(x + ls - 1) / ls] != '1')
		move_player(list, 0, 1, 1);
	if (updown == 0 && lr == 1 && list->map[y / ls][(x - 1) / ls] != '1' \
		&& list->map[(y + ls - 1) / ls][(x - 1) / ls] != '1')
		move_player(list, -1, 0, 1);
	if (updown == 0 && lr == 2 && list->map[y / ls][(x + ls) / ls] != '1' \
		&& list->map[(y + ls - 1) / ls][(x + ls) / ls] != '1')
		move_player(list, 1, 0, 1);
}

void	key_input(void *ptr)
{
	t_struct	*list;

	list = (t_struct *)ptr;
	key_close(list);
	if (mlx_is_key_down(list->mlx.mlx, MLX_KEY_UP))
		key(list, 1, 0);
	if (mlx_is_key_down(list->mlx.mlx, MLX_KEY_DOWN))
		key(list, 2, 0);
	if (mlx_is_key_down(list->mlx.mlx, MLX_KEY_LEFT))
		key(list, 0, 1);
	if (mlx_is_key_down(list->mlx.mlx, MLX_KEY_RIGHT))
		key(list, 0, 2);
}

void	converting_pngs(t_struct *list)
{
	list->pngs.coin = mlx_load_png("pngs/coin.png");
	list->pngs.exit = mlx_load_png("pngs/exit.png");
	list->pngs.wall = mlx_load_png("pngs/wall.png");
	list->pngs.floor = mlx_load_png("pngs/floor.png");
	list->pngs.player = mlx_load_png("pngs/player.png");
	list->images.coin = mlx_texture_to_image(list->mlx.mlx, list->pngs.coin);
	list->images.exit = mlx_texture_to_image(list->mlx.mlx, list->pngs.exit);
	list->images.floor = \
		mlx_texture_to_image(list->mlx.mlx, list->pngs.floor);
	list->images.player = \
		mlx_texture_to_image(list->mlx.mlx, list->pngs.player);
	list->images.wall = mlx_texture_to_image(list->mlx.mlx, list->pngs.wall);
}

mlx_image_t	*init(t_struct *list, char c)
{
	if (c == 'P')
		return (list->images.player);
	if (c == 'C')
		return (list->images.coin);
	if (c == 'E')
		return (list->images.exit);
	if (c == '0')
		return (list->images.floor);
	if (c == '1')
		return (list->images.wall);
	return (NULL);
}

void	initialyzing(t_struct *list, int i, int j, int indic)
{
	if (indic == 1 || indic == 2)
	{
		list->images.bgr = init(list, '0');
		mlx_resize_image(list->images.bgr, list->size, list->size);
		mlx_image_to_window(list->mlx.mlx, list->images.bgr, i, j);
	}
	if (indic == 2)
	{
		list->images.imgcoin = init(list, 'C');
		mlx_resize_image(list->images.imgcoin, list->size, list->size);
		mlx_image_to_window(list->mlx.mlx, list->images.imgcoin, i, j);
	}
	if (indic == 3)
	{
		list->images.bgr = \
			init(list, list->map[j / list->size][i / list->size]);
		mlx_resize_image(list->images.bgr, list->size, list->size);
		mlx_image_to_window(list->mlx.mlx, list->images.bgr, i, j);
	}
	if (indic == 4)
	{
		list->images.imgplr = init(list, 'P');
		mlx_resize_image(list->images.imgplr, list->size, list->size);
		mlx_image_to_window(list->mlx.mlx, list->images.imgplr, i, j);
	}
}

void	player_map(t_struct *list)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = -1;
	while (++j < list->rows)
	{
		i = -1;
		while (++i < list->clm)
		{
			if (list->map[j][i] == 'P')
			{
				initialyzing(list, i * list->size, j * list->size, 4);
				list->player.i = k;
				k++;
			}
			else if (list->map[j][i] != '1')
			{
				initialyzing(list, i * list->size, j * list->size, 4);
				list->images.imgplr->instances[k].enabled = false;
				k++;
			}
		}
	}
}

void	initialyzing_map(t_struct *list)
{
	int	i;
	int	j;

	j = 0;
	while (j < list->rows)
	{
		i = -1;
		while (++i < list->clm)
		{
			if (list->map[j][i] == 'P')
				initialyzing(list, i * list->size, j * list->size, 1);
			else if (list->map[j][i] == 'C')
				initialyzing(list, i * list->size, j * list->size, 2);
			else
				initialyzing(list, i * list->size, j * list->size, 3);
		}
		j++;
	}
}

int	creating_map(t_struct *list)
{
	int	size_x;
	int	size_y;

	size_x = list->clm * list->size;
	size_y = list->rows * list->size;
	list->mlx.mlx = mlx_init(size_x, size_y, "map", false);
	if (!(list->mlx.mlx))
		return (-1);
	list->images.bgr = mlx_new_image(list->mlx.mlx, size_x, size_y);
	list->images.imgplr = mlx_new_image(list->mlx.mlx, size_x, size_y);
	list->images.imgcoin = mlx_new_image(list->mlx.mlx, size_x, size_y);
	converting_pngs(list);
	initialyzing_map(list);
	player_map(list);
	move_player(list, list->player.x, list->player.y, 0);
	mlx_loop_hook(list->mlx.mlx, key_input, list);
	mlx_loop_hook(list->mlx.mlx, collect_coins, list);
	mlx_loop(list->mlx.mlx);
	mlx_terminate(list->mlx.mlx);
	return (0);
}
