/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:35:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/27 05:04:57 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_floor2_2(t_wolf *holder, float current[3], int i)
{
	float	weight;

	current[0] = ((float)HEIGHT) / (2 * i - HEIGHT);
	weight = current[0] / PERP_DIST_WALL;
	current[1] = weight * WALL_X_FL + (1.0 - weight) * P_X;
	current[1] = (fabsf(current[1]) < 1) ? 1 : current[1];
	current[2] = weight * WALL_Y_FL + (1.0 - weight) * P_Y;
}

void		draw_floor2(t_wolf *holder,\
unsigned int *buf, unsigned int x)
{
	int		i;
	float	current[3];
	int		tmp;
	int		var;

	tmp = holder->camera->draw_end;
	if (tmp == 767)
		tmp = holder->camera->floor;
	i = holder->height + abs(holder->updown) + abs(holder->extra_updown) + 1;
	while (--i > tmp - holder->updown - holder->extra_updown)
	{
		draw_floor2_2(holder, current, i);
		if (current[1] <= 0 || current[2] < 0)
			continue;
		var = HEIGHT - i + (holder->updown + holder->extra_updown);
		if (var < HEIGHT && var > 0)
		{
			buf[var * 1024 + x] = get_pixel(holder->camera->texture[7], \
						FTX >> 1, FTY);
			if (holder->shadows)
				buf[(var << 10) + x] = alter_color_fixed(buf[(var << 10) + x], \
				(int)((float)current[0] * 256) / 10);
		}
	}
}

void		draw_floor1_2(t_wolf *holder, float current[3], int i)
{
	float	weight;
	int		int_f;

	int_f = INT_F((i << 1) - holder->height - 2 * (holder->updown + \
		holder->extra_updown - holder->wall_height));
	int_f = (int_f == 0) ? 1 : int_f;
	current[0] = FIXED_F(FIX_DIV(INT_F(holder->height), int_f));
	weight = current[0] / PERP_DIST_WALL;
	current[1] = weight * WALL_X_FL + (1.0 - weight) * P_X;
	current[1] = (fabsf(current[1]) < 1) ? 1 : current[1];
	current[2] = weight * WALL_Y_FL + (1.0 - weight) * P_Y;
}

void		draw_floor1_3(t_wolf *holder, float current[3], float old_new[2])
{
	current[2] = (current[2] > holder->map_height) ? \
		holder->map_height : current[2];
	holder->wall_height = (holder->height_map[(int)current[2]][(int)current[1]\
	- 1] > 300) ? 300 / current[0] : holder->height_map[(int)current[2]]\
	[(int)current[1] - 1] / current[0];
	old_new[0] = old_new[1];
	old_new[1] = holder->height_map[(int)current[2]][(int)current[1] - 1];
}

void		draw_floor1(t_wolf *holder,\
unsigned int *buf, unsigned int x)
{
	int		i;
	float	current[3];
	float	old_new[2];

	i = holder->height;
	holder->state = 0;
	while (--i > holder->camera->draw_end)
	{
		draw_floor1_2(holder, current, i);
		if (current[1] <= 0 || current[2] < 0)
			continue;
		draw_floor1_3(holder, current, old_new);
		buf[(i << 10) + x] = \
			get_pixel(holder->camera->texture[4], FTX >> 1, FTY);
		if (holder->shadows)
			buf[i * 1024 + x] = alter_color_fixed(buf[i * 1024 + x],\
			(int)((float)current[0] * 256) / 10);
	}
}
