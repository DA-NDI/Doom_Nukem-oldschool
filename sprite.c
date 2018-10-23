/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:39:29 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 16:20:54 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define SPRITE sprite
#define SPRITE_X (sprite->x - P_X)
#define SPRITE_Y (sprite->y - P_Y)
#define START_X  sprite->draw_start_x
#define START_Y  sprite->draw_start_y
#define END_X sprite->draw_end_x
#define END_Y sprite->draw_end_y
#define TRANSFORM_Y sprite->transform_y
#define SPRITE_W sprite->sprite_width
#define X sprite->x
#define Y sprite->y
#define DIST_X (abs((int)X - (int)P_X))
#define DIST_Y (abs((int)Y - (int)P_Y))

void	restart_enemy(t_wolf *holder, t_sprite *sprite)
{
	printf("enemy restarted\n");
	holder->frags++;
	SHOOTS = 0;
	sprite->is_sprite = 1;
	sprite->x = sprite->orig_x;
	sprite->y = sprite->orig_y;
	sprite->is_alive = 1;
	sprite->speed = sprite->speed + 0.1;
	sprite->tex_sprite[0] = sprite->s_tex->arr_sprite[0][0];
	sprite->end_frame = 5;
}

void	burning_boss(t_sprite *sprite)
{
	printf("sprite->end_frame = %d sprite->shoots = %d\n", sprite->end_frame, sprite->shoots);
	if (IS_SPRITE && !sprite->is_alive && sprite->end_frame >= 5)
	{
		if (sprite->end_frame <= 7)
			CURR_TEX = sprite->s_tex->arr_sprite[1][sprite->end_frame];
		sprite->end_frame++;
	}
	sprite->end_frame = (sprite->end_frame == 8) ? 5 : sprite->end_frame;
	sprite->end_frame = (sprite->end_frame == 9) ? 8 : sprite->end_frame;
}

void	ft_move_boss(t_wolf *holder, t_sprite *sprite)
{
	printf("started moving\n");
	if (sprite->end_frame >= 9 && DIST_X <= 3 && DIST_Y <= 3)
	{
//		CURR_TEX = sprite->s_tex->arr_sprite[0][8];
		printf("restarted\n");
		get_player_coordinates(holder);
		restart_enemy(holder, sprite);
		holder->hud->lives -= 1;
//		SDL_Delay(5000);
//		printf("close in sprite\n");
//		ft_close(holder);
	}
	if (DIST_X <= 1 && DIST_Y <= 1 && sprite->end_frame < 9 && IS_SPRITE)
	{
		CURR_TEX = sprite->s_tex->arr_sprite[0][sprite->end_frame];
//		printf("CURR_TEX = %p\n", CURR_TEX);
		sprite->end_frame++;
		sprite->is_alive = (sprite->end_frame >= 8) ? 0 : 1;
	}
	if ((sprite->x != P_X || sprite->y != P_Y) && sprite->is_alive && !holder->pause)
	{
		if ((int)X < (int)P_X && MAP[(int)Y][(int)(X + 0.1)] == '0')
			sprite->x += sprite->speed;
		else if ((int)X > (int)P_X && MAP[(int)Y][(int)(X - 0.1)] == '0')
			sprite->x -= sprite->speed;
		else if ((int)Y > (int)P_Y && MAP[(int)(Y - 0.1)][(int)X] == '0')
			sprite->y -= sprite->speed;
		else if ((int)Y < (int)P_Y && MAP[(int)(Y + 0.1)][(int)X] == '0')
			sprite->y += sprite->speed;
	}
	burning_boss(sprite);
}

void	ft_move_bullet(t_wolf *holder, t_sprite *sprite)
{
	static float direction[2] = {0, 0};
	static int frames = 0;
	static int gun = 0;

	if (!sprite->is_alive)
	{
		direction[1] = holder->DIR_X;
		direction[0] = holder->DIR_Y;
		sprite->x = P_X + direction[1];
		sprite->y = P_Y + direction[0];
		gun = G;
	}
	else if(sprite->is_alive && !holder->pause)
	{
		printf("bullet moving\n");
		sprite->x += direction[1];
		sprite->y += direction[0];
		sprite->tex_sprite[0] = sprite->s_tex->arr_sprite[gun][frames++];
	}
	if (frames == 3)
		frames = 0;
	if (MAP[(int)sprite->y][(int)sprite->x] != '0' && sprite->is_alive)
	{
		MAP[(int)sprite->y][(int)sprite->x] = '5';
		sprite->is_alive = 0;
	}
}

/*
**Condition ifs in sprite_loop
**1) it's in front of camera plane so you don't see things behind you
**2) it's on the screen (left)
**3) it's on the screen (right)
**4) ZBuffer, with perpendicular distance
*/

void	ft_sprite_loop(t_wolf *holder, unsigned int buffer[holder->height][holder->width], \
						int sprite_height, int sprite_screen_x, t_sprite *sprite)
{
	int				tex_x;
	int				tex_y;
	unsigned int	color;
	int				i;
	int w;
float angle;


	w = sprite->tex_sprite[0]->w;
//	SDL_QueryTexture(sprite->tex_sprite[0], NULL, NULL, &w, NULL);
	START_X--;
	END_Y += holder->updown + holder->extra_updown;
	END_Y = (END_Y > 768) ? 768 : END_Y;
	 if (sprite->texture == 99)
	 {
	 	angle = roundf(atan2(sprite->y - P_Y, sprite->x - P_X) * (180 / 3.1415926));
	 	if (angle <= -135 && angle > -157.5)
			CURR_TEX = sprite->s_tex->arr_sprite[0][0]; 
	 	if (angle <= -112.5 && angle > -135)
			CURR_TEX = sprite->s_tex->arr_sprite[0][1]; 
	 	else if (angle <= -90 && angle > -112.5)
			CURR_TEX = sprite->s_tex->arr_sprite[0][2]; 
	 	else if (angle <= -67.5 && angle > -90)
			CURR_TEX = sprite->s_tex->arr_sprite[0][3];  
	 	else if (angle < -45 && angle > -67.5)
			CURR_TEX = sprite->s_tex->arr_sprite[0][4]; 
		else if (angle < -22.5 && angle > -45)
			CURR_TEX = sprite->s_tex->arr_sprite[0][5];  
	 	else if (angle <= -0 && angle > -22.5)
			CURR_TEX = sprite->s_tex->arr_sprite[0][6];  
	 	else if (angle >= 0 && angle < 22.5)
			CURR_TEX = sprite->s_tex->arr_sprite[0][7];  
	 	else if (angle >= 22.5 && angle < 45)
			CURR_TEX = sprite->s_tex->arr_sprite[1][0];  
	 	else if (angle >= 45 && angle < 67.5)
			CURR_TEX = sprite->s_tex->arr_sprite[1][1];  
	 	else if (angle >= 67.5 && angle < 90)
			CURR_TEX = sprite->s_tex->arr_sprite[1][2];  
	 	else if (angle >= 90 && angle < 112.5)
			CURR_TEX = sprite->s_tex->arr_sprite[1][3];  
	 	else if (angle >= 112.5 && angle < 135)
			CURR_TEX = sprite->s_tex->arr_sprite[1][4];  
	 	else if (angle >= 135 && angle < 157.5)
			CURR_TEX = sprite->s_tex->arr_sprite[1][5];  
	 	else if (angle >= 157.5 && angle <= 180)
			CURR_TEX = sprite->s_tex->arr_sprite[1][6];  
	 	else if (angle >= -180 && angle <= -157.5)
			CURR_TEX = sprite->s_tex->arr_sprite[1][7];  
	 }
	while (++START_X < END_X && (sprite->is_alive || IS_SPRITE))
	{
		tex_x = (int)(256 * (START_X - (-SPRITE_W / 2 + sprite_screen_x)) \
				* w / SPRITE_W) / 256;
		if (TRANSFORM_Y > 0 && START_X > 0 && START_X < WIDTH && \
				TRANSFORM_Y < holder->zbuffer[START_X])
		{
			i = START_Y - 1 + holder->updown + holder->extra_updown;
			i = (i >= 0) ? i : 0;
			while (++i < END_Y)
			{
tex_y = (i - HEIGHT / 2 + sprite_height / 2 - (holder->updown + holder->extra_updown)) * w / sprite_height;
				color = get_pixel(sprite->tex_sprite[0], tex_x, tex_y);
				if (color != 0)
					buffer[i][START_X] = color;
			}
		}
	}
}

// void sort_sprites(int* order, double* dist, int amount)
// {
// 	int gap;
// 	int swapped;

// 	gap = amount;
// 	swapped = 0;
//  	while(gap > 1 || swapped)
// 	{
//     //shrink factor 1.3
// 		gap = (gap * 10) / 13;
// 		if(gap == 9 || gap == 10)
// 			gap = 11;
//     	if (gap < 1) gap = 1;
//     		swapped = 0;
//     	for(int i = 0; i < amount - gap; i++)
//     	{
// 			int j = i + gap;
// 			if(dist[i] < dist[j])
//       		{
//       			std::swap(dist[i], dist[j]);
// 				std::swap(order[i], order[j]);
// 				swapped = 1;
//       		}
//     	}
// 	}
// }

// void 	create_sprites(t_wolf *holder, t_camera *camera, unsigned int **buffer)
// {
// 	int sprite_order[MAXSPRITES];
// 	float sprite_dist[MAXSPRITES];
// }

void	ft_draw_sprites(t_wolf *holder, t_camera *camera, \
						unsigned int buffer[holder->height][holder->width], t_sprite *sprite, int num)
{
	float	inv_det;
	float	transform_x;
	int		sprite_screen_x;
	int		sprite_height;

	float udiv = 1;
	float vdiv = 1;
//float vmove = 0;

	inv_det = 1.0 / (PLANE_X * DIR_Y - DIR_X * camera->plane_y);
	transform_x = inv_det * (DIR_Y * SPRITE_X - DIR_X * SPRITE_Y);
	TRANSFORM_Y = inv_det * (-camera->plane_y * SPRITE_X + PLANE_X * SPRITE_Y);
//int vmovescreen = (int)(vmove / TRANSFORM_Y);
	sprite_screen_x = (int)((WIDTH / 2) * (1 + transform_x / TRANSFORM_Y));
	sprite_height = (abs((int)(HEIGHT / (TRANSFORM_Y)))) * vdiv;
	START_Y = -sprite_height / 2 + HEIGHT / 2;// + vmovescreen;
	if (START_Y < 0)
		START_Y = 0;
	END_Y = sprite_height / 2 + HEIGHT / 2;// + vmovescreen;
	if (END_Y >= HEIGHT)
		END_Y = HEIGHT - 1;
	SPRITE_W = (abs((int)(HEIGHT / (TRANSFORM_Y)))) * udiv;
	START_X = -SPRITE_W / 2 + sprite_screen_x;
	if (START_X < 0)
		START_X = 0;
	END_X = SPRITE_W / 2 + sprite_screen_x;
	if (END_X >= WIDTH)
		END_X = WIDTH - 1;
	ft_sprite_loop(holder, buffer, sprite_height, sprite_screen_x, sprite);
}
