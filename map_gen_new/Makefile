# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 23:25:10 by azulbukh          #+#    #+#              #
#    Updated: 2018/10/18 19:25:06 by azulbukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map
SRC := main.c
MAKELIB = make -C libft/
LIBPATH = libft/libft.a
EFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SDL = -I ./Frameworks/SDL2_image.framework/Headers -I ./Frameworks/SDL2_ttf.framework/Headers
SDL2 = -I ./Frameworks/SDL2.framework/Headers 

#-rpath @loader_path/Frameworks 
SDL1 = -rpath @loader_path/Frameworks -F ./Frameworks/ -framework SDL2 -framework SDL2_ttf -framework SDL2_image

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH) $(OBJ)
	gcc -g -o $(NAME) $(EFLAGS) $(SDL2) $(SDL1) $(SDL) $(OBJ) $(LIBPATH)

$(LIBPATH):
	$(MAKELIB)

%.o:%.c
	gcc $(EFLAGS) -c $< -o $@ $(SDL) $(SDL2)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

