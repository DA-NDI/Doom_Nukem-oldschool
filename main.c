/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:24:47 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 17:21:38 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_close(t_wolf *holder)
{
	Mix_FreeChunk(holder->weapon[0]->pistol_shoot);
	Mix_FreeChunk(holder->weapon[1]->pistol_shoot);
	holder->weapon[0]->pistol_shoot = NULL;
	holder->weapon[1]->pistol_shoot = NULL;
	SDL_DestroyRenderer(holder->renderer);
	SDL_DestroyWindow(holder->window);
	holder->running = 0;
	free(holder->start);
	TTF_Quit();
	SDL_Quit();
	system("leaks doom-nukem");
	exit(0);
}

void		ft_print_error(char *str)
{
	ft_putendl(str);
	system("leaks doom-nukem");
	exit(1);
}

t_wolf		*holder_init(t_wolf *holder)
{
	holder->height = 768;
	holder->width = 1024;
	holder->running = 1;
	holder->shooting = 0;
	holder->advanced = normal;
	holder->fps = 60;
	holder->pause = 0;
	holder->starting = 1;
	holder->frame_delay = 15;
	holder->skybox_num = 0;
	holder->gun = 0;
	holder->frags = 0;
	holder->updown = 0;
	holder->adv_frames = 0;
	holder->start_point = 0;
	holder->lifted = 0;
	holder->extra_updown = 0;
	holder->shadows = 0;
	holder->state = 0;
	holder->sprite_tex = (t_sprite_tex**)malloc(sizeof(t_sprite_tex*) * 7);
	holder->sprite = (t_sprite**)malloc(sizeof(t_sprite*) * 17);
	holder->retry_state = 0;
	holder->ceiling = 1;
	return (holder);
}

void		start_game(t_wolf *holder)
{
	holder_init(holder);
	holder->line[0].x1 = 100;
	holder->line[0].y1 = 100;
	holder->line[0].x2 = 500;
	holder->line[0].y2 = 100;
	holder->line[1].x1 = 500;
	holder->line[1].y1 = 100;
	holder->line[1].x2 = 300;
	holder->line[1].y2 = 300;
	holder->line[2].x1 = 300;
	holder->line[2].y1 = 300;
	holder->line[2].x2 = 100;
	holder->line[2].y2 = 100;
	get_player_coordinates(holder);
	ft_init_image(holder);
	ft_start_screen(holder);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	Mix_PauseMusic();
	ft_hud_init(holder);
	ft_raycasting(holder, 0);
	system("leaks doom-nukem");
}

int			main(int argc, char **argv)
{
	static t_wolf	holder[1];

	if (argc != 2 || !argv[1])
		ft_print_error("Usage: ./doom-nukem <map>");
	holder->map = ft_create_map(argv, holder);
	ft_verify_map(holder->map, holder);
	start_game(holder);
	return (0);
}
