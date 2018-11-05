/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:44:32 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 22:20:41 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	reinit_death_star_sprite(t_wolf *holder)
{
	holder->sprite_tex[7]->amount = get_sprite_amount(holder, 'D');
	if (holder->sprite_tex[7]->amount == 1)
	{
		holder->sprites->num += 1;
		start_enemy(holder, 22, holder->sprite[22]);
		STAR->is_sprite = get_sprite_coordinates(holder, 'D', 22);
	}
}

void	load_sprite_death_star(t_wolf *holder)
{
	t_sprite_tex	*star;

	star = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[7] = star;
	star->arr_sprite[0][0] = load_image("sprites/death_star0.png");
	star->arr_sprite[0][1] = load_image("sprites/death_star1.png");
	star->arr_sprite[0][2] = load_image("sprites/death_star2.png");
	star->arr_sprite[0][3] = load_image("sprites/death_star3.png");
	star->arr_sprite[0][4] = load_image("sprites/death_star4.png");
	star->arr_sprite[0][5] = load_image("sprites/death_star5.png");
	star->arr_sprite[0][6] = load_image("sprites/death_star6.png");
	star->arr_sprite[0][7] = load_image("sprites/death_star7.png");
	star->arr_sprite[1][0] = load_image("sprites/death_star9.png");
	star->arr_sprite[1][1] = load_image("sprites/death_star10.png");
	star->arr_sprite[1][2] = load_image("sprites/death_star11.png");
	star->arr_sprite[1][3] = load_image("sprites/death_star12.png");
	star->arr_sprite[1][4] = load_image("sprites/death_star13.png");
	star->arr_sprite[1][5] = load_image("sprites/death_star14.png");
	star->arr_sprite[1][6] = load_image("sprites/death_star15.png");
	star->arr_sprite[1][7] = load_image("sprites/death_star16.png");
	star->amount = get_sprite_amount(holder, 'D');
	start_death_star(holder, 22);
}
