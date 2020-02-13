# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/02/13 17:30:41 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main_test.c display_map.c parsing/parsing.c \
			  parsing/parsing_elem.c parsing/error_free.c parsing/full_map.c \
			  color_map.c radar.c

LIBFT		= libft/libft.a

NAME		= cub3d

RM			= rm -f

CC			= gcc

CFLAGS		= 

MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	
			make re -C libft
			make clean -C libft
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) test.cub

libft:
			make re -C libft
			make clean -C libft

clean:      
			make clean -C libft
			rm -f $(NAME)

fclean:
			make fclean -C libft
			rm -f ${NAME}

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

all:		${NAME}

re:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) test.cub

re2:		clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) test2.cub

re3:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) test3.cub


.PHONY:		all clean fclean re re2 re3 libft
