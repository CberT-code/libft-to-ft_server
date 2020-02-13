/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:45 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/13 18:48:16 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# define CHECKER 255;


/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| R | C | F | S | EA| WE| SO| NO|
** 0 -> 4 = char **check
** 5 = int *F
** 6 = int *C
*/

# define ERROR_MAP_N_WALL "Error\nThe wall is open on the north side\n"
# define ERROR_MAP_W_WALL "Error\nThe wall is open on the west side\n"
# define ERROR_MAP_E_WALL "Error\nThe wall is open on the east side\n"
# define ERROR_MAP_S_WALL "Error\nThe wall is open on the south side\n"
# define ERROR_MAP_NO "Error\nNO MAP FOUND\n"
# define ERROR_MAP "Error\n MAP\n"
# define ERROR_PLAYER_NO_POS "Error\nNO PLAYER POSITION FOUND\n"
# define ERROR_PLAYER_EX_POS "Error\nTOO MANY PLAYER POSITION FOUND\n"
# define ERROR_NO_FILE "Error\nNO FILE FOUND\n"
# define ERROR_ELEM "Error\nELEMENT IS MISSING\n"
# define VITESSE 4
# define VITESSEROTATION (M_PI_2 / 50)

typedef struct			s_key
{
	int					key;
	struct s_key		*next;
}						t_key;

typedef struct			s_coord
{
	int					y;
	int					x;
}						t_coord;

typedef struct			s_lmap
{
	int					size;
	char				*str;
	struct s_lmap		*next;
}						t_lmap;

typedef struct	s_image
{
	void	*image;
	int		height;
	int		width;
	int		bpp;
	int		size_l;
	int		endian;
	int 	*buffer;
}				t_image;

typedef struct			s_map
{
	char				**tab_map;
	t_lmap				*line;
	int					tab_line;
	int					line_len;
	int					x_max;
	int					y_max;
}						t_map;

typedef struct			s_player
{
	int					pos_x;
	int					pos_y;
	t_coord				*coord;
	t_image				*img;
	float				angle;
	float				vitess;
	int					position;
	int					move_up;
	int					move_down;
	int					move_left;
	int					move_right;
	int					watch_right;
	int					watch_left;
}						t_player;

typedef struct			s_elem
{
	short				bit_elem;
	char				**texture;
	int					R[2];
	int					F[3];
	int					C[3];
}						t_elem;

typedef struct			s_mini
{
	t_image				*img;
	int					t_case;
	int					ligne;
	int					display;
}						t_mini;

typedef struct			s_data
{
	void				*ptr;
	void				*win;
	t_elem				*elem;
	t_image				*img;
	t_mini				*mini;
	t_map				*map;
	t_player			*player;
	t_key				*key;
}						t_data;

typedef struct			s_radar
{
	float				b;
	float				y;
	float				x;
	float				t;
	float				angle;
	float				width;
}						t_radar;

/* 
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/

int			num_player(t_data *data, t_map *map);
int			num_player2(t_data *data, int j, int h);
int			fill_int(int bit, char *str, int *tab, short *bit_elem);
int			fill_int_rgb(int bit, char *str, int *tab, short *bit_elem);
int			check_elem(char *str, t_elem *elem, t_data *data);
int			calc_dst_vector(t_coord *coord, int actual_x, int actual_y);
void		full_map(t_map *map);
void		fill_str(int bit, char *str, t_elem *elem);
void		parsing_elem(char *str, t_elem *elem);
void		init_struct(t_data *data);
void		free_elem(t_data *data);
void		*ft_error_map(char *str, t_data *data, int i);
void		*ft_error(char *str, t_data *data);
void		*check_map(t_data *data);
void		map_str(char *str, t_map *map);
void		*check_map(t_data *data);
void		check_map2(t_data *data, int j);
void		full_map(t_map *map);
void		parsing(char *doc_map, t_data *data);
void		mini_map(t_data *data, t_elem *elem);
void		init_mini(t_data *data, t_elem *elem, t_mini *mini);
void		calcul_coord(t_player *player, t_map *map, int t_case);
void		display_map(t_data *data, t_map *map, int t_case);
void		map_color_case(t_data *data, int y, int x, int t_case);
void		color_square(int i, t_mini *mini, int color, int mult);
void		draw_circle(int ligne, t_image *img, t_data *data, int radius);
void		display_player(t_data *data, t_map *map, int t_case);
void		vision(t_data *data);
void		init_radar(t_radar *R, t_data *data);
void		radar(t_data *data);

# endif
