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

#include <wolf3d.h>

void	start_enemy(t_wolf *holder, t_sprite *sprite)
{
	static int shoots = 0;

	ARCADE_TEX = sprite->arr_sprite[0][0];
	sprite->speed = 0.1;
}

void	start_car(t_wolf *holder, t_sprite *sprite)
{
	ARCADE_TEX = sprite->arr_sprite[0][0];
	sprite->speed = 0.1;
}

void	load_sprite_arcade(t_wolf *holder, int num)
{
	t_sprite	*sprite;

	sprite = (t_sprite*)malloc(sizeof(t_sprite));
	holder->sprite[num] = sprite;
	holder->sprite[num]->is_alive = 0;
	sprite->tex_sprite[0] = NULL;
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
	sprite->is_sprite = get_sprite_coordinates(holder, 'A', num);
	sprite->end_frame = 5;
	sprite->shoots = 0;
	start_enemy(holder, sprite);
}

void	load_sprite_bullet(t_wolf *holder)
{
	t_sprite	*bullet;

	bullet = (t_sprite*)malloc(sizeof(t_sprite));
	holder->sprite[1] = bullet;
	bullet->is_alive = 0;
	bullet->sprite_found = 1;
	bullet->tex_sprite[0] = NULL;
	bullet->arr_sprite[0][0] = load_image("resourses/pistol_bullet0.png");
	bullet->arr_sprite[0][1] = load_image("resourses/pistol_bullet1.png");
	bullet->arr_sprite[0][2] = load_image("resourses/pistol_bullet2.png");
	bullet->arr_sprite[0][3] = load_image("resourses/pistol_bullet3.png");
	bullet->arr_sprite[1][0] = load_image("resourses/bullet_fire.png");
	bullet->arr_sprite[1][1] = load_image("resourses/bullet_fire1.png");
	bullet->arr_sprite[1][2] = load_image("resourses/bullet_fire2.png");
	bullet->arr_sprite[1][3] = load_image("resourses/bullet_fire3.png");
	bullet->x = P_X + holder->DIR_X;
	bullet->y = P_Y + holder->DIR_Y;
	bullet->orig_x = bullet->x;
	bullet->orig_y = bullet->y;
	bullet->speed = 0.5;
	bullet->is_sprite = 0;
//	bullet->is_sprite = get_sprite_coordinates(holder, 'A', 1);
	start_car(holder, bullet);
	// bullet->arr_sprite[0][1] = load_image("sprites/arcade1.png");
	// bullet->arr_sprite[0][2] = load_image("sprites/arcade2.png");
	// bullet->arr_sprite[0][3] = load_image("sprites/arcade3.png");
	// bullet->arr_sprite[0][4] = load_image("sprites/arcade4.png");
	// bullet->arr_sprite[1][0] = load_image("sprites/arcade.png");
	// bullet->arr_sprite[1][1] = load_image("sprites/arcade1_g.png");
	// bullet->arr_sprite[1][2] = load_image("sprites/arcade2_g.png");
	// bullet->arr_sprite[1][3] = load_image("sprites/arcade3_g.png");
	// bullet->arr_sprite[1][4] = load_image("sprites/arcade4_g.png");
}

void	load_sprite_car(t_wolf *holder)
{
	t_sprite	*car;

	car = (t_sprite*)malloc(sizeof(t_sprite));
	holder->sprite[2] = car;
	car->is_alive = 0;
	car->sprite_found = 0;
	car->tex_sprite[0] = NULL;
	car->texture = 1;
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
	car->shoots = 0;
car->x = P_X + holder->DIR_X;
	car->y = P_Y + holder->DIR_Y;
	car->orig_x = car->x;
	car->orig_y = car->y;

	car->speed = 0.5;
	car->is_sprite = 0;
	car->is_sprite = get_sprite_coordinates(holder, 'C', 2);
	start_enemy(holder, car);

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
	load_sprite_arcade(holder, 0);
	load_sprite_bullet(holder);
 	load_sprite_arcade(holder, 2);
	start->play_select = 1;
	start->start_screen = load_tex(RENDER, "textures/init_screen_1024.jpg");
	SDL_RenderClear(holder->renderer);
	SDL_RenderCopy(holder->renderer, holder->start->start_screen, NULL, NULL);
	draw_text(holder, " > Play", holder->width / 2 - 10, holder->height / 2);
	draw_text(holder, "	  Quit", WIDTH / 2 - 10, HEIGHT / 2 + 15);
	draw_text(holder, "PRESS ENTER TO SELECT", WIDTH / 2, HEIGHT - 25);
	SDL_RenderPresent(holder->renderer);
}
