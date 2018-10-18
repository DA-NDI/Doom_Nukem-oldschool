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
#define SPRITE holder->sprite
#define SPRITE_X (holder->sprite->x - P_X)
#define SPRITE_Y (holder->sprite->y - P_Y)
#define START_X (holder->sprite->draw_start_x)
#define START_Y (holder->sprite->draw_start_y)
#define END_X (holder->sprite->draw_end_x)
#define END_Y (holder->sprite->draw_end_y)
#define TRANSFORM_Y (holder->sprite->transform_y)
#define SPRITE_W (holder->sprite->sprite_width)
#define X sprite->x
#define Y sprite->y
#define DIST_X (abs((int)X - (int)P_X))
#define DIST_Y (abs((int)Y - (int)P_Y))
#define IS_SPRITE holder->sprite->is_sprite

void	restart_enemy(t_wolf *holder)
{
	holder->frags++;
	SHOOTS = 0;
	IS_SPRITE = 1;
	holder->sprite->x = holder->sprite->orig_x;
	holder->sprite->y = holder->sprite->orig_y;
	holder->sprite->is_alive = 1;
	holder->sprite->speed = holder->sprite->speed + 0.1;
	ARCADE_TEX = holder->sprite->arr_sprite[0][0];
}

void	burning_boss(t_wolf *holder, t_sprite *sprite, int *end_frame)
{
	static int i = 9;

	if (IS_SPRITE && !sprite->is_alive && *end_frame == 5)
	{
		ARCADE_TEX = holder->sprite->arr_sprite[0][i];
		i++;
	}
	i = (i == 12) ? 9 : i;
}

void	ft_move_boss(t_wolf *holder, t_sprite *sprite)
{
	printf("hey!\n");
	static int end_frame = 5;

	if (end_frame == 9 && DIST_X <= 3 && DIST_Y <= 3)
	{
		SDL_Delay(5000);
		ft_close(holder);
	}
	if (DIST_X <= 1 && DIST_Y <= 1 && end_frame < 9 && IS_SPRITE)
	{
		ARCADE_TEX = holder->sprite->arr_sprite[0][end_frame];
		end_frame++;
		sprite->is_alive = (end_frame == 8) ? 0 : 1;
	}
	if ((sprite->x != P_X || sprite->y != P_Y) && holder->sprite->is_alive)
	{
		if ((int)X < (int)P_X && MAP[(int)Y][(int)(X + 0.1)] == '0')
			sprite->x += holder->sprite->speed;
		else if ((int)X > (int)P_X && MAP[(int)Y][(int)(X - 0.1)] == '0')
			sprite->x -= holder->sprite->speed;
		else if ((int)Y > (int)P_Y && MAP[(int)(Y - 0.1)][(int)X] == '0')
			sprite->y -= holder->sprite->speed;
		else if ((int)Y < (int)P_Y && MAP[(int)(Y + 0.1)][(int)X] == '0')
			sprite->y += holder->sprite->speed;
	}
	burning_boss(holder, sprite, &end_frame);
}

/*
**Condition ifs in sprite_loop
**1) it's in front of camera plane so you don't see things behind you
**2) it's on the screen (left)
**3) it's on the screen (right)
**4) ZBuffer, with perpendicular distance
*/

void	ft_sprite_loop(t_wolf *holder, unsigned int buffer[][holder->width], \
						int sprite_height, int sprite_screen_x)
{
	int				tex_x;
	int				tex_y;
	unsigned int	color;
	int				i;

	START_X--;
	END_Y += holder->updown + holder->extra_updown;
	END_Y = (END_Y > 768) ? 768 : END_Y;
	while (++START_X < END_X && (holder->sprite->is_alive || IS_SPRITE))
	{
		tex_x = (int)(256 * (START_X - (-SPRITE_W / 2 + sprite_screen_x)) \
				* 64 / SPRITE_W) / 256;
		if (TRANSFORM_Y > 0 && START_X > 0 && START_X < WIDTH && \
				TRANSFORM_Y < holder->sprite->zbuffer[START_X])
		{
			i = START_Y - 1 + holder->updown + holder->extra_updown;
			while (++i < END_Y)
			{
tex_y = (i - HEIGHT / 2 + sprite_height / 2 - (holder->updown + holder->extra_updown)) * 64 / sprite_height;
				color = get_pixel(holder->sprite->tex_sprite[0], tex_x, tex_y);
				if (color != 0)
					buffer[i][START_X] = color;
			}
		}
	}
}

void sort_sprites(int* order, double* dist, int amount)
{
	int gap;
	int swapped;

	gap = amount;
	swapped = 0;
 	while(gap > 1 || swapped)
	{
    //shrink factor 1.3
		gap = (gap * 10) / 13;
		if(gap == 9 || gap == 10)
			gap = 11;
    	if (gap < 1) gap = 1;
    		swapped = 0;
    	for(int i = 0; i < amount - gap; i++)
    	{
			int j = i + gap;
			if(dist[i] < dist[j])
      		{
      			std::swap(dist[i], dist[j]);
				std::swap(order[i], order[j]);
				swapped = 1;
      		}
    	}
	}
}

void 	create_sprites(t_wolf *holder, t_camera *camera, unsigned int buffer[][holder->width])
{
	int sprite_order[MAXSPRITES];
	float sprite_dist[MAXSPRITES];
}

void	ft_draw_sprites(t_wolf *holder, t_camera *camera, \
						unsigned int buffer[][holder->width])
{
	float	inv_det;
	float	transform_x;
	int		sprite_screen_x;
	int		sprite_height;

	inv_det = 1.0 / (PLANE_X * DIR_Y - DIR_X * camera->plane_y);
	transform_x = inv_det * (DIR_Y * SPRITE_X - DIR_X * SPRITE_Y);
	TRANSFORM_Y = inv_det * (-camera->plane_y * SPRITE_X + \
					PLANE_X * SPRITE_Y);
	sprite_screen_x = (int)((WIDTH / 2) * (1 + transform_x / TRANSFORM_Y));
	sprite_height = abs((int)(HEIGHT / (TRANSFORM_Y)));
	START_Y = -sprite_height / 2 + HEIGHT / 2;
	if (START_Y < 0)
		START_Y = 0;
	END_Y = sprite_height / 2 + HEIGHT / 2;
	if (END_Y >= HEIGHT)
		END_Y = HEIGHT - 1;
	SPRITE_W = abs((int)(HEIGHT / (TRANSFORM_Y)));
	START_X = -SPRITE_W / 2 + sprite_screen_x;
	if (START_X < 0)
		START_X = 0;
	END_X = SPRITE_W / 2 + sprite_screen_x;
	if (END_X >= WIDTH)
		END_X = WIDTH - 1;
	ft_sprite_loop(holder, buffer, sprite_height, sprite_screen_x);
}
