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

t_sprite	*start_enemy(t_wolf *holder, int num)
{
	t_sprite *sprite;

	sprite = (t_sprite*)malloc(sizeof(t_sprite));
	holder->sprite[num] = sprite;
	sprite->shoots = 0;
	sprite->speed = 0.1;
	sprite->is_alive = 0;
	sprite->sprite_found = 0;
	sprite->is_sprite = 0;
	sprite->end_frame = 0;

	return (sprite);
}


void 	start_arcade_sprite(t_wolf *holder, int num)
{
	t_sprite 	*sprite;

	sprite = start_enemy(holder, num);
	sprite->is_sprite = get_sprite_coordinates(holder, 'A', num);
	sprite->end_frame = 5;
	sprite->s_tex = holder->sprite_tex[0];
	holder->sprite[num] = sprite;
	sprite->tex_sprite[0] = holder->sprite_tex[0]->arr_sprite[0][0];
}

void 	start_bullet_sprite(t_wolf *holder, int num)
{
	t_sprite 	*bullet;

	bullet = start_enemy(holder, num);
	bullet->s_tex = holder->sprite_tex[1];
	bullet->x = P_X + holder->DIR_X;
	bullet->y = P_Y + holder->DIR_Y;
	bullet->orig_x = bullet->x;
	bullet->orig_y = bullet->y;
	bullet->speed = 0.5;
	bullet->sprite_found = 1;
	bullet->tex_sprite[0] = holder->sprite_tex[1]->arr_sprite[0][0];
}

void 	start_car_sprite(t_wolf *holder, int num)
{
	t_sprite  	*car;

	car = start_enemy(holder, num);
	car->s_tex = holder->sprite_tex[2];
	car->is_sprite = get_sprite_coordinates(holder, 'C', num);
	car->texture = 99;
	car->tex_sprite[0] = holder->sprite_tex[2]->arr_sprite[0][0];
}

void	load_sprite_tex_arcade(t_wolf *holder)
{
	t_sprite_tex	*sprite;
	int 		 	tmp;

	tmp = -1;
	sprite = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[0] = sprite;
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
	sprite->amount = get_sprite_amount(holder, 'A');
	while (++tmp < sprite->amount)
		start_arcade_sprite(holder, tmp + 2);
	printf("amount ARCADE = %d\n", sprite->amount);
	
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

void 	reload_sprites(t_wolf *holder)
{
	int tmp;

	tmp = -1;
	holder->sprite_tex[0]->amount = get_sprite_amount(holder, 'A');
	while (++tmp < holder->sprite_tex[0]->amount)
		start_arcade_sprite(holder, tmp + 2);
}

void	load_sprite_tex_car(t_wolf *holder)
{
	t_sprite_tex	*car;
	int 		 	tmp;

	tmp = -1;
	car = (t_sprite_tex*)malloc(sizeof(t_sprite_tex));
	holder->sprite_tex[2] = car;
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
	car->amount = get_sprite_amount(holder, 'C');
	while (++tmp < car->amount && tmp < 3)
	{
		printf("car started at %d\n", tmp);
		start_car_sprite(holder, tmp + 7);
	}
	printf("amount CAR = %d\n", car->amount);

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

	load_sprite_tex_arcade(holder);
	load_sprite_tex_bullet(holder);
 	load_sprite_tex_car(holder);
// 	start_arcade_sprite(holder, 2);
//	start_arcade_sprite(holder, 3);
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
