/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:49:13 by cbauer            #+#    #+#             */
/*   Updated: 2025/02/08 14:58:51 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_default(t_struct *list, t_check *ck, int indic) //muss noch restlcihen variablen hinzufügen aber bahn kommt in 10 min
{
	if (indic == 0)
	{
		list->argv = NULL;
		list->moves = 0;
		list->map = NULL;
		list->player.x = 0;
		list->player.y = 0;
		list->coin = 0;
		list->coins = NULL;
		list->rows = 0;
		list->clm = 0;
	}
	else if (indic == 1)
	{
		ck->p = 0;
		ck->c = 0;
		ck->e = 0;
	}
}

// int main(int argc, char *argv[])
// {
// 	t_struct list;
	
	// list.collectpos[0].x
	// list.collectpos[0].y
	// set_default(&list, NULL, 0);
	// list.map[list.collectpos[0].x][list.collectpos[0].y]
	// check_for_valid_input(&list, argv); 
			//ob .ber file 
			//check mit open --- ob geöffnet werden kann --- ob leer ist
			//ob filecontent valid ist | mit gnl --- valide Zeichen "0, 1, P, C, E"
			//checken ob die map rechteckig ist -- alle Zeilen gleiche Länge

			// creating_map();
			//map allocieren --- char double array
			//doublearray mit map initialyzen | GNL nutzen
			//bei failen free | freecase function

			// checking_map();
			//floodfill -> um playability der map zu checken | alle collectibles && exit reachable?
			//ob player == 1 && finish == 1 && collectible > 1 ist 
			//ob Rand der Map nur aus 1 besteht | erste && letzte Zeile == 1 | erste und letzte Randzeile == 1?
	//printing error message?? -- 	leon??
			//freecase bei Errors
	
	// creating_image();  //study about function die mir png datei in map umwandelt

	// init_map();	//map.ber
	// mlx_new_window()
	//mlx_init()
	//mlx_put_image_to_window() --- für Wände && Boden
	

	//mlx_init()
	//Collectibles && spieler && Exit
	//list.player_x && list.player_y
	
	// game();
	//WASD - movement
	//ESC  - exit --- mlx_destroy_window
	//Bewegung des Spielers updaten (mlx_clear_window), mlx_piut_image_to_window
	//collectibles sammeln --- list.collectibles--
	//checking end of game --- wenn list.collectibles == 0 && player == exit
// }



// am Ende mit Valgrind checken 

void	get_size(t_struct *list)
{
	int max;

	if (list->rows > list->clm)
		max = list->rows;
	else
		max = list->clm;
	if (max <= 5)
		list->size = 150;
	else if (max <= 20)
		list->size = 100;
	else if (max <= 50)
		list->size = 50;
}

int main(int argc, char *argv[])
{
	t_struct	list;
	
	if (argc == 2)
	{
		set_default(&list, NULL, 0);
		if (checking_input(&list, argv) < 0)
			return (-1);
		get_size(&list);
		
		if (creating_map(&list) < 0)
			return (-1);
	}
	else
		return (perror("Error\nPlease enter a map!"), -1);
	return (0);
}