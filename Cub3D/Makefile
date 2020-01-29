# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/01/29 19:10:22 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= main_test.c display_map.c parsing/parsing.c parsing/parsing_elem.c parsing/error_free.c parsing/full_map.c

LIBFT		= libft/libft.a

NAME		= cub3d

RM			= rm -f

CC			= gcc

CFLAGS		= 

MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	$(LIBFT)
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

re:			clean all

.PHONY:		all clean fclean re libft
