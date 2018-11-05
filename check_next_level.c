/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_level.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:54:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 20:25:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_free_create_map(t_wolf *holder, int i)
{
	holder->hud->level++;
	while (holder->map[++i])
		free(holder->map[i]);
	i = -1;
	while (holder->height_map[++i])
		free(holder->height_map[i]);
	if (holder->hud->level == 2)
		holder->map = ft_create_map("./maps/2", holder);
	else if (holder->hud->level == 3)
		holder->map = ft_create_map("./maps/3", holder);
	else if (holder->hud->level == 4)
		holder->map = ft_create_map("./maps/4", holder);
	else if (holder->hud->level == 5)
		holder->map = ft_create_map("./maps/5", holder);
	else
	{
		draw_text(holder, "RAKAMAKAFO!!! THE BEST OF THE BEST!!!", \
		WIDTH / 2, HEIGHT / 2);
		SDL_RenderPresent(holder->renderer);
		SDL_Delay(4000);
		ft_close(holder);
	}
	ft_verify_map(holder->map, holder);
	get_player_coordinates(holder, 'P');
}

void	reinit_sprites_1(t_wolf *holder, int a)
{
	holder->sprite_tex[4]->amount = get_sprite_amount(holder, 'H');
	while (++a < holder->sprite_tex[4]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 13, POT);
		POT->is_sprite = get_sprite_coordinates(holder, 'H', a + 13);
	}
	a = -1;
	holder->sprite_tex[5]->amount = get_sprite_amount(holder, 'S');
	while (++a < holder->sprite_tex[5]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 16, PEPSI);
		PEPSI->is_sprite = get_sprite_coordinates(holder, 'S', a + 16);
	}
	a = -1;
	holder->sprite_tex[6]->amount = get_sprite_amount(holder, 'K');
	while (++a < holder->sprite_tex[6]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 19, KOLA);
		KOLA->is_sprite = get_sprite_coordinates(holder, 'K', a + 19);
	}
	reinit_death_star_sprite(holder);
}

void	reinit_sprites_2(t_wolf *holder, int a)
{
	holder->sprite_tex[3]->amount = get_sprite_amount(holder, 'G');
	while (++a < holder->sprite_tex[3]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 10, AMO);
		AMO->is_sprite = get_sprite_coordinates(holder, 'G', a + 10);
	}
	a = -1;
	holder->sprite_tex[0]->amount = get_sprite_amount(holder, 'A');
	while (++a < holder->sprite_tex[0]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 2, ARC);
		CAR->is_sprite = get_sprite_coordinates(holder, 'A', a + 2);
		CAR->end_frame = 5;
	}
	a = -1;
	holder->sprite_tex[2]->amount = get_sprite_amount(holder, 'C');
	while (++a < holder->sprite_tex[2]->amount)
	{
		holder->sprites->num += 1;
		start_enemy(holder, a + 7, CAR);
		ARC->is_sprite = get_sprite_coordinates(holder, 'C', a + 7);
	}
}

void	init_invisible(t_wolf *holder)
{
	holder->transparent = 1;
	holder->line[0].x1 = 20;
	holder->line[0].y1 = 18;
	holder->line[0].x2 = 25;
	holder->line[0].y2 = 10;
	holder->line[1].x1 = 25;
	holder->line[1].y1 = 10;
	holder->line[1].x2 = 30;
	holder->line[1].y2 = 18;
	holder->line[2].x1 = 30;
	holder->line[2].y1 = 18;
	holder->line[2].x2 = 20;
	holder->line[2].y2 = 18;
}

void	ft_check_next_level(t_wolf *holder)
{
	int		a;
	int		num;

	num = 0;
	a = -1;
	if (holder->frags >= 5)
	{
		Mix_PlayChannel(-1, holder->camera->sound[4], 0);
		init_invisible(holder);
		init_mode(holder, holder->start->play_select);
		holder->sprites->num = 0;
		ft_free_create_map(holder, -1);
		holder->ceiling = 0;
		holder->frags = 0;
		reinit_sprites_1(holder, -1);
		reinit_sprites_2(holder, -1);
		ft_sort_sprites_put(holder, holder->sprites, 0);
	}
}
