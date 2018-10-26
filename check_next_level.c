/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_level.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:54:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/26 15:39:04 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_free_create_map(t_wolf *holder)
{
	int		i;

	i = -1;
	holder->hud->level++;
	while (holder->map[++i])
		free(holder->map[i]);
	i = -1;
	while (holder->height_map[++i])
		free(holder->height_map[i]);
	if (holder->hud->level == 2)
		holder->map = ft_create_map("./maps/2", holder);
	else
		holder->map = ft_create_map("./maps/2", holder);
	get_player_coordinates(holder, 'P');
}

void	reinit_sprites_1(t_wolf *holder, int a, int num)
{
	holder->sprite_tex[4]->amount = get_sprite_amount(holder, 'H');
	while (++a < holder->sprite_tex[4]->amount)
	{
		printf("potion\n");
		num = num + 1;
		start_enemy(holder, a + 13, POT);
		POT->is_sprite = get_sprite_coordinates(holder, 'H', a + 13);
	}
	a = -1;
	holder->sprite_tex[5]->amount = get_sprite_amount(holder, 'S');
	while (++a < holder->sprite_tex[5]->amount)
	{
		printf("pepsis\n");
		num = num + 1;
		start_enemy(holder, a + 16, PEPSI);
		PEPSI->is_sprite = get_sprite_coordinates(holder, 'S', a + 16);
	}
	a = -1;
	holder->sprite_tex[6]->amount = get_sprite_amount(holder, 'K');
	while (++a < holder->sprite_tex[6]->amount)
	{
		printf("kola\n");
		num = num + 1;
		start_enemy(holder, a + 19, KOLA);
		KOLA->is_sprite = get_sprite_coordinates(holder, 'K', a + 19);
	}
}

void	reinit_sprites_2(t_wolf *holder, int a, int num)
{
	holder->sprite_tex[3]->amount = get_sprite_amount(holder, 'G');
	while (++a < holder->sprite_tex[3]->amount)
	{
		printf("ammo\n");
		num = num + 1;
		start_enemy(holder, a + 10, AMO);
		AMO->is_sprite = get_sprite_coordinates(holder, 'G', a + 10);
	}
	a = -1;
	holder->sprite_tex[0]->amount = get_sprite_amount(holder, 'A');
	while (++a < holder->sprite_tex[0]->amount)
	{
		printf("arcade\n");
		num = num + 1;
		start_enemy(holder, a + 2, CAR);
		CAR->is_sprite = get_sprite_coordinates(holder, 'A', a + 2);
		CAR->end_frame = 5;
	}
	a = -1;
	holder->sprite_tex[2]->amount = get_sprite_amount(holder, 'C');
	while (++a < holder->sprite_tex[2]->amount)
	{
		printf("car\n");
		num = num + 1;
		start_enemy(holder, a + 7, ARC);
		ARC->is_sprite = get_sprite_coordinates(holder, 'C', a + 7);
	}
	holder->sprites->num = num;
}

void	ft_check_next_level(t_wolf *holder)
{
	int		a;
	int		num;

	num = 0;
	a = -1;
	if (holder->frags >= 1)
	{
		printf("RELOADED!\n");
		holder->sprites->num = 0;
		ft_free_create_map(holder);
		holder->ceiling = 0;
		holder->frags = 0;
		reinit_sprites_1(holder, -1, num);
		reinit_sprites_2(holder, -1, num);
		printf("amount in next level before sort = %d\n", holder->sprite_tex[0]->amount);
		ft_sort_sprites_put(holder, holder->sprites, 0);
	}
}
