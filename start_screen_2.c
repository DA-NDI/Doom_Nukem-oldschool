/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:12:29 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/23 13:12:29 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	load_sprite_tex_arcade_2(t_sprite_tex *sprite)
{
	sprite->arr_sprite[0][0] = load_image("sprites/arcade.png");
	sprite->arr_sprite[0][1] = load_image("sprites/arcade1.png");
	sprite->arr_sprite[0][2] = load_image("sprites/arcade2.png");
	sprite->arr_sprite[0][3] = load_image("sprites/arcade3.png");
	sprite->arr_sprite[0][4] = load_image("sprites/arcade4.png");
	sprite->arr_sprite[0][5] = load_image("sprites/arcade_end1.png");
	sprite->arr_sprite[0][6] = load_image("sprites/arcade_end2.png");
	sprite->arr_sprite[0][7] = load_image("sprites/arcade_end3.png");
	sprite->arr_sprite[0][8] = load_image("sprites/arcade_end4.png");
	sprite->arr_sprite[1][0] = load_image("sprites/arcade.png");
	sprite->arr_sprite[1][1] = load_image("sprites/arcade1_g.png");
	sprite->arr_sprite[1][2] = load_image("sprites/arcade2_g.png");
	sprite->arr_sprite[1][3] = load_image("sprites/arcade3_g.png");
	sprite->arr_sprite[1][4] = load_image("sprites/arcade4_g.png");
	sprite->arr_sprite[1][5] = load_image("sprites/arcade4.png");
	sprite->arr_sprite[1][6] = load_image("sprites/arcade4_b1.png");
	sprite->arr_sprite[1][7] = load_image("sprites/arcade4_b2.png");
}

void	load_sprite_tex_arcade(t_wolf *holder)
{
	t_sprite_tex	*sprite;
	int				tmp;

	tmp = -1;
	sprite = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[0] = sprite;
	load_sprite_tex_arcade_2(sprite);
	sprite->amount = get_sprite_amount(holder, 'A');
	while (++tmp < 5)
		start_arcade_sprite(holder, tmp + 2);
}

void	load_sprite_tex_bullet(t_wolf *holder)
{
	t_sprite_tex	*bullet;

	bullet = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[1] = bullet;
	bullet->arr_sprite[0][0] = load_image("resourses/pistol_bullet0.png");
	bullet->arr_sprite[0][1] = load_image("resourses/pistol_bullet1.png");
	bullet->arr_sprite[0][2] = load_image("resourses/pistol_bullet2.png");
	bullet->arr_sprite[0][3] = load_image("resourses/pistol_bullet3.png");
	bullet->arr_sprite[1][0] = load_image("resourses/bullet_fire.png");
	bullet->arr_sprite[1][1] = load_image("resourses/bullet_fire1.png");
	bullet->arr_sprite[1][2] = load_image("resourses/bullet_fire2.png");
	bullet->arr_sprite[1][3] = load_image("resourses/bullet_fire3.png");
}

void	load_sprite_tex_car_2(t_sprite_tex *car)
{
	car->arr_sprite[0][0] = load_image("sprites/car_test16-0.png");
	car->arr_sprite[0][1] = load_image("sprites/car_test16-1.png");
	car->arr_sprite[0][2] = load_image("sprites/car_test16-2.png");
	car->arr_sprite[0][3] = load_image("sprites/car_test16-3.png");
	car->arr_sprite[0][4] = load_image("sprites/car_test16-4.png");
	car->arr_sprite[0][5] = load_image("sprites/car_test16-5.png");
	car->arr_sprite[0][6] = load_image("sprites/car_test16-6.png");
	car->arr_sprite[0][7] = load_image("sprites/car_test16-7.png");
	car->arr_sprite[1][0] = load_image("sprites/car_test16-8.png");
	car->arr_sprite[1][1] = load_image("sprites/car_test16-9.png");
	car->arr_sprite[1][2] = load_image("sprites/car_test16-10.png");
	car->arr_sprite[1][3] = load_image("sprites/car_test16-11.png");
	car->arr_sprite[1][4] = load_image("sprites/car_test16-12.png");
	car->arr_sprite[1][5] = load_image("sprites/car_test16-13.png");
	car->arr_sprite[1][6] = load_image("sprites/car_test16-14.png");
	car->arr_sprite[1][7] = load_image("sprites/car_test16-15.png");
}

void	load_sprite_tex_car(t_wolf *holder)
{
	t_sprite_tex	*car;
	int				tmp;

	tmp = -1;
	car = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[2] = car;
	load_sprite_tex_car_2(car);
	car->amount = get_sprite_amount(holder, 'C');
	while (++tmp < 3)
	{
		start_car_sprite(holder, tmp + 7);
	}
}
