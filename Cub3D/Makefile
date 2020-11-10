# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 12:24:21 by ichejra           #+#    #+#              #
#    Updated: 2020/11/05 11:25:09 by ichejra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D.a

SRCS =  bmp.c\
		ceil_color.c\
		draw_map.c\
		floor_color.c\
		get_res.c\
		handle_map.c\
		handle_map_utils.c\
		init.c\
		key_press.c\
		line_loop.c\
		main.c\
		skip.c\
		sort_sprite.c\
		sprite.c\
		store_map.c\
		texture.c\
		draw_map_utils.c\
		ft_free.c\
		error_man.c\
		get_tex.c\
		check_save.c\
		line_loop_utils.c\
		check_map_chars.c


SRC_LIB =       libft/ft_strlen.c\
				libft/ft_strchr.c\
                libft/ft_atoi.c libft/ft_isdigit.c \
                libft/ft_strdup.c \
                libft/ft_strtrim.c \
                libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strcmp_bonus.c\
				libft/ft_isspace.c libft/ft_memcpy.c

SRC_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_LIB = $(SRC_LIB:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

OBJ = $(SRCS:.c=.o)

LINKERFLAG = -Wall -Wextra -Werror -c
LIBS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB) $(OBJ_GNL)
		@ar rcs $(NAME) $(OBJ) $(OBJ_LIB) $(OBJ_GNL)
		@gcc $(NAME) $(LIBS) -o cub3D
		@echo "DONE"
%.o: %.c
		@gcc $(LINKERFLAG) $< -o $@

clean:
		@rm -f *.o
		@rm -f libft/*.o
		@rm -f gnl/*.o

fclean: clean
		@rm -f $(NAME)
		@rm -f cub3D

re: fclean all