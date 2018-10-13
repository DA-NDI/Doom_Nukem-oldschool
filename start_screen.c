/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:56:32 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/18 12:11:03 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	start_enemy(t_wolf *holder, t_sprite *sprite)
{
	static int shoots = 0;

	holder->shoots = &shoots;
	ARCADE_TEX = sprite->arr_sprite[0][0];
	holder->sprite->speed = 0.1;
}

void	load_sprite_arcade(t_wolf *holder)
{
	t_sprite	*sprite;

	sprite = (t_sprite*)malloc(sizeof(t_sprite));
	holder->sprite = sprite;
	holder->sprite->is_alive = 0;
	sprite->tex_sprite[0] = NULL;
	sprite->arr_sprite[0][0] = load_image("resourses/arcade.png");
	sprite->arr_sprite[0][1] = load_image("resourses/arcade1.png");
	sprite->arr_sprite[0][2] = load_image("resourses/arcade2.png");
	sprite->arr_sprite[0][3] = load_image("resourses/arcade3.png");
	sprite->arr_sprite[0][4] = load_image("resourses/arcade4.png");
	sprite->arr_sprite[0][5] = load_image("resourses/arcade_end1.png");
	sprite->arr_sprite[0][6] = load_image("resourses/arcade_end2.png");
	sprite->arr_sprite[0][7] = load_image("resourses/arcade_end3.png");
	sprite->arr_sprite[0][8] = load_image("resourses/arcade_end4.png");
	sprite->arr_sprite[0][9] = load_image("resourses/arcade4.png");
	sprite->arr_sprite[0][10] = load_image("resourses/arcade4_b1.png");
	sprite->arr_sprite[0][11] = load_image("resourses/arcade4_b2.png");
	sprite->arr_sprite[1][0] = load_image("resourses/arcade.png");
	sprite->arr_sprite[1][1] = load_image("resourses/arcade1_g.png");
	sprite->arr_sprite[1][2] = load_image("resourses/arcade2_g.png");
	sprite->arr_sprite[1][3] = load_image("resourses/arcade3_g.png");
	sprite->arr_sprite[1][4] = load_image("resourses/arcade4_g.png");
	sprite->is_sprite = get_sprite_coordinates(holder, 'A');
	start_enemy(holder, sprite);
}

void	ft_start_screen(t_wolf *holder)
{
	t_camera	*camera;
	t_start		*start;

	camera = (t_camera*)malloc(sizeof(t_camera));
	holder->weapon[0] = (t_weapon*)malloc(sizeof(t_weapon));
	holder->weapon[1] = (t_weapon*)malloc(sizeof(t_weapon));
	holder->weapon[2] = (t_weapon*)malloc(sizeof(t_weapon));
	holder->weapon[3] = (t_weapon*)malloc(sizeof(t_weapon));
	start = (t_start*)malloc(sizeof(t_start));
	ft_camera_init(camera, holder);
	init_weapon(holder->weapon[0], holder);
	init_weapon_grenade(holder->weapon[1], holder);
	init_weapon_demon(holder->weapon[2], holder);
	init_weapon_shotgun(holder->weapon[3], holder);
	holder->camera = camera;
	holder->start = start;
	load_sprite_arcade(holder);
	start->play_select = 1;
	start->start_screen = load_tex(RENDER, "textures/init_screen_1024.jpg");
	SDL_RenderClear(holder->renderer);
	SDL_RenderCopy(holder->renderer, holder->start->start_screen, NULL, NULL);
	draw_text(holder, " > Play", holder->width / 2 - 10, holder->height / 2);
	draw_text(holder, "	  Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
	draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
	SDL_RenderPresent(holder->renderer);
}
