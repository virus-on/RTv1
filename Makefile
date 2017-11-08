# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 15:22:42 by vpopovyc          #+#    #+#              #
#    Updated: 2017/09/13 15:11:05 by mpaziuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = main.c \
      antialiasing.c \
      compute_cylinder.c \
      scene_1.c \
      scene_2.c \
      vector_tools.c \
      vector_tools2.c \
      sphere.c \
      cone.c \
      compute_cone.c \
      plane.c \
      cylinder.c \
      draw.c \
      tools.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -O3 -pthread
GFLAGS = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(GFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

