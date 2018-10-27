/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:44:32 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 16:56:22 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	reinit_death_star_sprite(t_wolf *holder)
{
	holder->sprite_tex[7]->amount = get_sprite_amount(holder, 'D');
	if (holder->sprite_tex[7]->amount > 0)
	{
		holder->sprites->num += 1;
		start_enemy(holder, 22, holder->sprite[22]);
		STAR->is_sprite = get_sprite_coordinates(holder, 'D', 22);
	}
}

void	load_sprite_death_star(t_wolf *holder)
{
	t_sprite_tex	*star;
	int				tmp;

	tmp = -1;
	star = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[7] = star;
	star->arr_sprite[0][0] = load_image("sprites/death_star1.png");
	star->arr_sprite[0][1] = load_image("sprites/death_star2.png");
	star->arr_sprite[0][2] = load_image("sprites/death_star3.png");
	star->arr_sprite[0][3] = load_image("sprites/death_star4.png");
	star->amount = get_sprite_amount(holder, 'D');
	while (++tmp < 1)
	{
		start_death_star(holder, tmp + 22);
	}
}
