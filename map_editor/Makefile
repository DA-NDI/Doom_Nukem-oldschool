# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 23:25:10 by azulbukh          #+#    #+#              #
#    Updated: 2018/10/25 18:09:21 by avolgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map
SRC := aizen.c asuna.c kakuzu.c lelush.c main.c megumin.c naruto.c sagiri.c saito.c subaru.c suzumia.c
MAKELIB = make -C ./../src/libft
LIBPATH = ./../src/libft/libft.a
EFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SDL = -I ./../src/SDL/SDL2_image.framework/Headers -I ./../src/SDL/SDL2_ttf.framework/Headers

SDL2 = -I ./../src/SDL/SDL2.framework/Headers

SDL1 = -rpath @loader_path/../src/sdl -F ./../src/SDL -framework SDL2 -framework SDL2_image -framework SDL2_ttf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH) $(OBJ)
	gcc -g -o $(NAME) $(EFLAGS) $(SDL2) $(SDL1) $(SDL) $(OBJ) $(LIBPATH)

$(LIBPATH):
	$(MAKELIB)

%.o:%.c
	gcc $(EFLAGS) -c $< -o $@ $(SDL) $(SDL2) -I ./../src/libft/includes

clean:
	rm -f $(OBJ)
	make -C ./../src/libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./../src/libft fclean

re: fclean all
