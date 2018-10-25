/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_4_nps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:34:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/23 14:31:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	start_pickup_sprite(t_wolf *holder, int tex, char c, int num)
{
	t_sprite	*pickup;

	pickup = (t_sprite*)malloc(sizeof(t_sprite));
	start_enemy(holder, num, pickup);
	pickup->s_tex = holder->sprite_tex[tex];
	pickup->is_sprite = get_sprite_coordinates(holder, c, num);
	pickup->tex_sprite[0] = holder->sprite_tex[tex]->arr_sprite[0][0];
}

void	load_sprite_tex_pickup(t_wolf *holder, int tex, char c, char *path)
{
	t_sprite_tex	*pick;
	int				tmp;

	tmp = -1;
	pick = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[tex] = pick;
	pick->amount = get_sprite_amount(holder, c);
	pick->arr_sprite[0][0] = load_image(path);
	while (++tmp < 3)
	{
		start_pickup_sprite(holder, tex, c, tmp + 10 + 3 * (tex - 3));
	}
}

void	load_pickupers(t_wolf *holder)
{
	load_sprite_tex_pickup(holder, 3, 'G', "sprites/ammo.png");
	load_sprite_tex_pickup(holder, 4, 'H', "sprites/potion.png");
	load_sprite_tex_pickup(holder, 5, 'S', "sprites/pepsi.png");
	load_sprite_tex_pickup(holder, 6, 'K', "sprites/cola.png");
}
