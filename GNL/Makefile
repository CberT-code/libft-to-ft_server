# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/03/24 14:59:58 by cyrillebert      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	*.a

NAME		= gnl.a

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	
		 	gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)
			./$(NAME) maps/test.cu
clean:      
			rm -f $(NAME)

fclean:
			make fclean 			rm -f ${NAME}

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

all:		${NAME}

re:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)
			./$(NAME) maps/test.cub

re2:		clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)
			./$(NAME) maps/test2.cub

re3:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)
			./$(NAME) maps/test3.cub


.PHONY:		all clean fclean re re2 r