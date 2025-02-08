#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE_X 1024
# define SIZE_Y 1024
# define SIZE 50

# include <stdio.h>
# include <errno.h>
# include <unistd.h> // may not be needed
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_pos
{
	int	x;
	int	y;
	int	collct;
}	t_pos;

typedef struct s_plr
{
	int	x;
	int	y;
	int	i;
}	t_plr;

typedef struct s_check
{
	int	p;
	int	e;
	int	c;
}	t_check;

typedef struct s_pngs
{
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}	t_pngs;

typedef struct s_images
{
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*bgr;
	mlx_image_t	*imgplr;
	mlx_image_t	*imgcoin;
}	t_images;

typedef struct s_mlx
{
	mlx_t *mlx;
	mlx_image_t *img;
	mlx_image_t	*img2;
	mlx_texture_t	*png;
	mlx_texture_t	*floor;
	mlx_image_t		*floor1;
	mlx_texture_t		*wall;
	mlx_image_t			*wallimg;
}	t_mlx;

typedef struct s_struct
{
	char		**argv;
	int			moves;
	char		**map;
	t_plr		player;
	int			coin;
	t_pos		*coins;  //muss allokieren  -- for each 
	int			rows; //muss nnoch init m,it 0
	int			clm;
	int			been_there_exit[2];
	int			temp;
	t_pngs		pngs;
	t_images	images;
	t_mlx		mlx;
	int			size;
	int			size2;
	

}	t_struct;


int	checking_input(t_struct *list, char **argv);
int	flood_fill_check_func(t_struct *list);
void	fl_checking(t_struct *list, int x, int y, int *finish);
int	valid_extras(t_struct *list);
int	init_coins(t_struct *list, t_check *ck);
int	open_func(t_struct *list);
int	valid_border(t_struct *list);
int	valid_char(t_struct *list);
int	open_func3(t_struct *list);
char	*grid_func(t_struct *list, char *temp);
int	open_func2(t_struct *list, int fd);
int	checking_name(char **argv);
int	ft_strcmp(char *str, char *src);
void	reset_map(t_struct *list);
int	checking_for_coins(t_struct *list, int i, int j);



void	set_default(t_struct *list, t_check *ck, int indic);
int		creating_map(t_struct *list);
void	initialyzing(t_struct *list, int i, int j, int indic);
mlx_image_t	*init(t_struct *list, char c);
void	converting_pngs(t_struct *list);
void	key_input(void *ptr);
void	move_player(t_struct *list, int p_x, int p_y, int indic);
void	initialyzing_map(t_struct *list);




#endif