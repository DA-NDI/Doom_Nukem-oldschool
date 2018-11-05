/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:39:29 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 22:19:43 by avolgin          ###   ########.fr       */
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

/*
**Condition ifs in sprite_loop
**1) it's in front of camera plane so you don't see things behind you
**2) it's on the screen (left)
**3) it's on the screen (right)
**4) ZBuffer, with perpendicular distance
*/

void	ft_sprite_loop_3(t_sprite *sprite, float angle)
{
	if (angle >= 22.5 && angle < 45)
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

void	ft_sprite_loop_2(t_sprite *sprite, float angle)
{
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
	ft_sprite_loop_3(sprite, angle);
}

void	ft_sprite_loop_loop(t_wolf *holder, t_sprite *sprite,\
unsigned int *buffer, int spr_int_w[4])
{
	int				tex_x;
	int				tex_y;
	int				i;
	unsigned int	color;
	int				coefficient;

	coefficient = (int)((float)sprite->distance * 256) / 70;
	tex_x = (int)(256 * (START_X - (-SPRITE_W / 2 + spr_int_w[0])) *\
	spr_int_w[2] / SPRITE_W) / 256;
	if (TRANSFORM_Y > 0 && START_X > 0 && START_X < WIDTH && TRANSFORM_Y\
	< holder->zbuffer[START_X])
	{
		i = START_Y - 1 + holder->updown + holder->extra_updown;
		i = (i >= 0) ? i : 0;
		while (++i < END_Y)
		{
			tex_y = (i - HEIGHT / 2 + spr_int_w[1] / 2 - (holder->updown +\
			holder->extra_updown - spr_int_w[3])) * spr_int_w[2] / spr_int_w[1];
			color = get_pixel(sprite->tex_sprite[0], tex_x, tex_y);
			if (holder->shadows && color != 0)
				color = alter_color_fixed(color, coefficient);
			if (color != 0)
				buffer[i * 1024 + START_X] = color;
		}
	}
}

void	ft_sprite_loop(t_wolf *holder,\
unsigned int *buffer,\
int spr_int[3], t_sprite *sprite)
{
	int spr_int_w[4];
	int w;

	w = sprite->tex_sprite[0]->w;
	START_X--;
	END_Y += holder->updown + holder->extra_updown;
	END_Y = (END_Y > 768) ? 768 : END_Y;
	if (sprite->texture == 99)
		ft_sprite_loop_2(sprite, roundf(atan2(sprite->y - P_Y, sprite->x - P_X)\
		* (180 / 3.1415926)));
	if (sprite->texture == 66)
		ft_sprite_loop_2(sprite, roundf(atan2(sprite->y - P_Y, sprite->x - P_X)\
		* (180 / 3.1415926)));
	while (++START_X < END_X && (sprite->is_alive || IS_SPRITE))
	{
		spr_int_w[0] = spr_int[0];
		spr_int_w[1] = spr_int[1];
		spr_int_w[2] = w;
		spr_int_w[3] = spr_int[2];
		ft_sprite_loop_loop(holder, sprite, buffer, spr_int_w);
	}
}

void	ft_draw_sprites(t_wolf *holder, t_camera *camera,\
unsigned int *buffer, t_sprite *sprite)
{
	float	inv_det;
	float	transform_x;
	int		spr_int[3];
	float	div[2];

	if (!sprite->is_sprite)
		return ;
	div[0] = 1;
	div[1] = 1;
	spr_int[2] = (int)(0.0 / TRANSFORM_Y);
	inv_det = 1.0 / (PLANE_X * DIR_Y - DIR_X * camera->plane_y);
	transform_x = inv_det * (DIR_Y * SPRITE_X - DIR_X * SPRITE_Y);
	TRANSFORM_Y = inv_det * (-camera->plane_y * SPRITE_X + PLANE_X * SPRITE_Y);
	spr_int[0] = (int)((WIDTH / 2) * (1 + transform_x / TRANSFORM_Y));
	spr_int[1] = (abs((int)(HEIGHT / (TRANSFORM_Y)))) * div[1];
	START_Y = -spr_int[1] / 2 + HEIGHT / 2 + spr_int[2];
	START_Y = (START_Y < 0) ? 0 : START_Y;
	END_Y = spr_int[1] / 2 + HEIGHT / 2 + spr_int[2];
	END_Y = (END_Y >= HEIGHT) ? HEIGHT - 1 : END_Y;
	SPRITE_W = (abs((int)(HEIGHT / (TRANSFORM_Y)))) * div[0];
	START_X = -SPRITE_W / 2 + spr_int[0];
	START_X = (START_X < 0) ? 0 : START_X;
	END_X = SPRITE_W / 2 + spr_int[0];
	END_X = (END_X >= WIDTH) ? WIDTH - 1 : END_X;
	ft_sprite_loop(holder, buffer, spr_int, sprite);
}
