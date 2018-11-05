/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:02:41 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/26 22:14:18 by avolgin          ###   ########.fr       */
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
#define MP_CELL MAP[(int)s->y][(int)s->x]
#define SPEED sprite->speed

void	restart_enemy(t_wolf *holder, t_sprite *sprite)
{
	Mix_PlayChannel(-1, holder->camera->sound[1], 0);
	holder->frags++;
	SHOOTS = 0;
	sprite->is_sprite = 1;
	sprite->x = sprite->orig_x;
	sprite->y = sprite->orig_y;
	sprite->is_alive = 1;
	sprite->speed = sprite->speed + 0.3;
	sprite->tex_sprite[0] = sprite->s_tex->arr_sprite[0][0];
	sprite->end_frame = 5;
}

void	burning_boss(t_sprite *sprite)
{
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
	if (sprite->end_frame >= 9 && DIST_X <= 3 && DIST_Y <= 3)
	{
		get_player_coordinates(holder, '0');
		restart_enemy(holder, sprite);
		holder->hud->lives -= 1;
	}
	if (DIST_X <= 1 && DIST_Y <= 1 && sprite->end_frame < 9 && IS_SPRITE)
	{
		CURR_TEX = sprite->s_tex->arr_sprite[0][sprite->end_frame];
		sprite->end_frame++;
		sprite->is_alive = (sprite->end_frame >= 8) ? 0 : 1;
	}
	if ((sprite->x != P_X || sprite->y != P_Y) &&\
	sprite->is_alive && !holder->pause && holder->starting == 0)
	{
		if ((int)X < (int)P_X && MAP[(int)Y][(int)(X + SPEED)] == '0')
			sprite->x += sprite->speed;
		else if ((int)X > (int)P_X && MAP[(int)Y][(int)(X - SPEED)] == '0')
			sprite->x -= sprite->speed;
		else if ((int)Y > (int)P_Y && MAP[(int)(Y - SPEED)][(int)X] == '0')
			sprite->y -= sprite->speed;
		else if ((int)Y < (int)P_Y && MAP[(int)(Y + SPEED)][(int)X] == '0')
			sprite->y += sprite->speed;
	}
	burning_boss(sprite);
}

void	ft_destroy_bullet(t_wolf *holder, t_sprite *s)
{
	MAP[(int)s->y][(int)s->x] = MAP[(int)s->y][(int)s->x] + 13;
	s->is_alive = 0;
	s->is_sprite = 0;
}

void	ft_move_bullet(t_wolf *holder, t_sprite *s)
{
	static float	direction[2] = {0, 0};
	static int		fr_gun[2] = {0, 0};

	if (!s->is_alive)
	{
		direction[1] = holder->DIR_X;
		direction[0] = holder->DIR_Y;
		s->x = P_X + direction[1];
		s->y = P_Y + direction[0];
		fr_gun[1] = (G > 1) ? 1 : G;
	}
	else if (s->is_alive && !holder->pause)
	{
		s->x += direction[1];
		s->y += direction[0];
		s->tex_sprite[0] = s->s_tex->arr_sprite[fr_gun[1]][fr_gun[0]++];
	}
	fr_gun[0] = (fr_gun[0] == 3 || fr_gun[0] == 2) ? 0 : fr_gun[0];
	s->is_alive = ((int)s->y > (int)holder->map_height || (int)s->x > \
	(int)holder->map_width || (int)s->y < 0 || (int)s->x < 0) ? 0 : s->is_alive;
	s->is_sprite = (s->is_alive) ? 1 : 0;
	if (s->is_alive && MP_CELL != '0' && MP_CELL <= '9')
		ft_destroy_bullet(holder, s);
}
