# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelbiad <mbelbiad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 21:17:57 by mbelbiad          #+#    #+#              #
#    Updated: 2022/05/08 12:33:44 by mbelbiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRC = so_long.c get_next_line_utils.c get_next_line.c draw_so_long.c split.c move_right.c \
		the_perfect_image.c move_up.c move_down.c move_left.c ft_printf.c ft_putstrr.c map_check.c 
OBJS = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
re: fclean all
.PHONY : all clean fclean re