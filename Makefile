# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/10/27 22:50:41 by avolgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

SRC_WOLF =./init.c \
	./main.c \
	validate.c \
	player_coordinates.c \
	raycasting.c \
	weapon.c \
	skybox.c \
	mainloop.c \
	loaders.c \
	drawers.c \
	start_screen.c \
	extra_keys.c \
	sprite.c \
	weapon_extra.c \
	drawers_extra.c \
	keys_azaporoz.c \
	draw_hud.c \
	check_jump_fly_etc.c \
	keys_azaporoz_2.c start_screen_2.c start_screen_3_nps.c \
	draw_floor_main.c \
	get_pixel.c \
	raycasting_2.c \
	raycasting_loop_draw_walls.c \
	sprite_2.c \
	mainloop_2.c \
	start_screen_4_nps.c \
	pickup.c \
	validate2.c \
	validate3.c	\
	bullet_collision.c \
	sorting__drawing_sprites.c \
	close_error.c \
	check_next_level.c \
	init_mode.c \
	draw_menu.c \
	init_weapons.c \
	line_azap.c \
	load_star.c

OBJECT_WOLF = $(SRC_WOLF:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES_WOLF = -I ./includes/

INCLUDES_LIBFT = -I ./src/libft/includes

INCLUDES_SDL2 = -I ./src/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./src/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./src/SDL/SDL2_mixer.framework/Headers

LIBFT = ./src/libft/libft.a

INCLUDES_SDL2_TTF = -I ./src/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./src/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_WOLF)
	make -C ./src/libft
	make -C ./map_editor
	@echo "\033[0;32mDoom-nukem compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/src/sdl $(FRAMEWORK_SDL2) $(OBJECT_WOLF) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c
	gcc	-g $(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

clean:
	make -C ./map_editor clean
	make -C ./src/libft clean
	/bin/rm -f $(OBJECT_WOLF)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./map_editor/map
	/bin/rm -f ./src/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c includes/*.h
