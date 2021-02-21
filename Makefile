# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 16:02:05 by mchaya            #+#    #+#              #
#    Updated: 2021/02/21 15:07:34 by mchaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC = $(addprefix inter/,intersect_plane.c intersect_sphere.c intersect_square.c \
	intersect_triangle.c intersection.c intersect_cylinder.c \
	intersect_cylinder1.c) main.c $(addprefix utils/,make_color.c \
	primary_ray.c vector_utils.c save_bmp.c return_free.c free_obj.c \
	utils.c utils1.c)
SRC += $(addprefix parser/, parser.c get_next_line.c ft_atoi.c parser1.c\
	get_next_line_utils.c parser2.c parser3.c parser4.c parser5.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -Ilibft -g -I.
all: $(NAME)
libmlx.a:
	$(MAKE) -C minilibx/
	mv minilibx/libmlx.dylib .
$(NAME): $(OBJ) libmlx.a
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L. -lmlx -Llibft -lft
debug: $(OBJ) libmlx.a
	gcc -g $(OBJ) -L. -lmlx -Llibft -lft -Ilibft
bonus: all
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C minilibx clean
	$(MAKE) -C libft fclean
re: fclean all
.PHONY: all clean fclean re bonus