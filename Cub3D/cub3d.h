/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:45 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 00:09:22 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# define CHECKER 255;


/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| R | C | F | S | EA| WE| SO| NO|
** 0 -> 4 = char **check
** 5 = int *F
** 6 = int *C
*/

# define ERROR_MAP_F_WALL "Error\nThe wall is open on the north side\n"
# define ERROR_MAP_S_WALL "Error\nThe wall is open on the west side\n"
# define ERROR_MAP_FE_WALL "Error\nThe wall is open on the east side\n"
# define ERROR_MAP_E_WALL "Error\nThe wall is open on the south side\n"
# define ERROR_MAP_NO "Error\nNO MAP FOUND\n"
# define ERROR_MAP "Error\n MAP\n"
# define ERROR_PLAYER_NO_POS "Error\nNO PLAYER POSITION FOUND\n"
# define ERROR_PLAYER_EX_POS "Error\nTOO MANY PLAYER POSITION FOUND\n"
# define ERROR_NO_FILE "Error\nNO FILE FOUND\n"
# define ERROR_ELEM "Error\nELEMENT IS MISSING\n"

typedef struct			s_lmap
{
	int					size;
	char				*str;
	struct s_lmap		*next;
}						t_lmap;

typedef struct			s_map
{
	char				position;
	char				**tab_map;
	t_lmap				*line;
	char				*str_map;
	int					tab_line;
	int					line_len;
}						t_map;

typedef struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				pos_angle;
	double				vitess;
}						t_player;

typedef struct			s_elem
{
	short				bit_elem;
	char				**check;
	int					R[2];
	int					F[3];
	int					C[3];
	t_map				*map;
	t_player			*player;
}						t_elem;

typedef struct			data_s
{
	void				*mlx_ptr;
	void				*mlx_win;
}						data_t;

/* 
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/

int			num_player(char *str, t_elem *elem);
int			fill_int(int bit, char *str, int *tab, short *bit_elem);
int			fill_int_rgb(int bit, char *str, int *tab, short *bit_elem);
int			check_elem(char *str, t_elem *elem);
int			check_str_map(t_elem *elem);
void		full_map(t_map *map);
void		fill_str(int bit, char *str, t_elem *elem);
void		parsing_elem(char *str, t_elem *elem);
void		init_struct(t_elem *elem);
void		*free_elem(t_elem *elem);
void		*ft_error_map(char *str, t_elem *elem, int i);
void		*ft_error(char *str, t_elem *elem);
void		*check_map(t_elem *elem);
void		map_str(char *str, t_map *map);
void		*check_map(t_elem *elem);
void		full_map(t_map *map);
t_elem		*parsing(char *doc_map);

# endif
