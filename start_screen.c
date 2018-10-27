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

void	reload_sprites(t_wolf *holder)
{
	int	tmp;

	tmp = -1;
	holder->sprite_tex[0]->amount = get_sprite_amount(holder, 'A');
	while (++tmp < holder->sprite_tex[0]->amount)
		start_arcade_sprite(holder, tmp + 2);
}

void	ft_start_screen_2(t_wolf *holder, t_camera *camera, t_start *start)
{
	ft_camera_init(camera, holder);
	init_weapon(holder->weapon[0], holder);
	init_weapon_grenade(holder->weapon[1], holder);
	init_weapon_demon(holder->weapon[2], holder);
	init_weapon_shotgun(holder->weapon[3], holder);
	holder->camera = camera;
	holder->start = start;
	load_sprite_tex_arcade(holder);
	load_sprite_tex_bullet(holder);
	load_sprite_tex_car(holder);
	load_sprite_death_star(holder);
	load_pickupers(holder);
}

void	ft_start_screen1(t_wolf *holder)
{
	draw_text(holder, " > Load map", holder->width / 2 - 10, \
		holder->height / 2);
	draw_text(holder, "	  Create map", WIDTH / 2 - 10, HEIGHT / 2 + 15);
	draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
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
	ft_start_screen_2(holder, camera, start);
	start_bullet_sprite(holder, 0);
	start_bullet_sprite(holder, 1);
	start->play_select = 1;
	start->start_screen = load_tex(RENDER, "textures/init_screen_1024.jpg");
	SDL_RenderClear(holder->renderer);
	SDL_RenderCopy(holder->renderer, holder->start->start_screen, NULL, NULL);
	draw_text(holder, " > Play", holder->width / 2 - 10, holder->height / 2);
	draw_text(holder, "	  Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
	draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
	SDL_RenderPresent(holder->renderer);
}
