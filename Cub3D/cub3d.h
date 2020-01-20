
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

# define ERROR_MAP_F_WALL "Error\nThe map doesn't start with a full wall\n"
# define ERROR_MAP_S_WALL "Error\nThe line map number %d doesn't start with a wall\n"
# define ERROR_MAP_FE_WALL "Error\nThe line map number %d doesn't finish with a wall\n"
# define ERROR_MAP_E_WALL "Error\nThe map doesn't end with a full wall\n"
typedef struct			s_elem
{
	short				bit_elem;
	char				**check;
	int					R[2];
	int					F[3];
	int					C[3];
}						t_elem;

/* 
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/
typedef struct			s_map
{
	int					lenght;
	char				position;
	char				**tab_map;
	char				*str_map;
	int					tab_len;
	int					line_len;
}						t_map;

int		fill_int(int bit, char *str, int *tab, short *bit_elem);
int		fill_int_rgb(int bit, char *str, int *tab, short *bit_elem);
int		fill_str(int bit, char *str, t_elem *elem);
void	parsing_elem(char *str, t_elem *elem);

# endif
