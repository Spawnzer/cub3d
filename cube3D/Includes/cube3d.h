/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*   By: adubeau <adubeau@student.42quebec.com>       +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:47:38 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/08/01 14:47:50 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>
# include <libft.h>
# include <math.h>
# include "raycasting.h"

# define WW 640
# define WH 640
# define FOV 60
#define PI 3.14159265

enum	e_key
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
	ARROW_L = 123,
	ARROW_R = 124,
};

enum	e_mouse
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum	e_element
{
	NO = 1,
	SO = 2,
	WE = 3,
	EA = 4,
	F = 5,
	C = 6,
	IN = 7,
	OUT = 8,
	UNK = 9,
	N = 78,
	S = 83,
	E = 69,
	W = 87,
	TILES = 50,
};

typedef struct s_texture
{
	void		*img;
	int			width;
	int			height;
	int 		count;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_img
{
	t_texture	*NO;
	t_texture	*SO;
	t_texture	*WE;
	t_texture	*EA;
	int			F;
	int			C;
	int			init;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	//t_rays 		*raycasting;
	int			map_y;
	int			map_x;
	int			pos;
	float		pos_x;
	float		pos_y;
	int			player_side;
	int			item;
	int			enemy_win;
	int			end_game;
	int			steps;
	int			time;
	int 		init;
	int 		radian;
	int 		playerAngle;
	int 		rotation;
	float 		playerCos;
	float 		playerSin;
	double 		speed;
}				t_vars;

typedef struct s_check_map
{
	int	y;
	int	x;
	int	s_y;
	int	s_x;
	int	dir;
}				t_check_map;

	//1-0_check_element.c

void	read_element(int fd);

	//1-1_check.c

void	check_map(int fd);

	//2_init.c

t_vars	*ft_t_vars(void);
t_img	*ft_t_img(void);
void	init_texture(t_vars *vars, t_texture *txt, char *element);
void	init_color(int *color, char *element);

	//4_put.c

void	put_game(void);


	//5_move.c

	int	read_key(int keycode, t_vars *vars);
int	get_keycode(int keycode);
void ft_up(t_vars *vars);
void ft_down(t_vars *vars);
void ft_left(t_vars *vars);
void ft_right(t_vars *vars);
void ft_esc(t_vars *vars);




//6_utils.c

int		perror_cube3d(char *str, int flag);
void	free_cube3d(t_vars *vars);
void	size_map();
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int	close_game(t_vars *vars);

// void	print_map(t_vars *vars);

#endif
