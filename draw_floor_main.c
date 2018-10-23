/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:35:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/23 13:35:12 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			draw_floor2_2(t_wolf *holder, float current[3], int i)
{
	float	weight;

	current[0] = ((float)HEIGHT) / (2 * i - HEIGHT);
	weight = current[0] / PERP_DIST_WALL;
	current[1] = weight * WALL_X_FL + (1.0 - weight) * P_X;
	current[1] = (fabsf(current[1]) < 1) ? 1 : current[1];
	current[2] = weight * WALL_Y_FL + (1.0 - weight) * P_Y;
}

void			draw_floor2(t_wolf *holder,\
unsigned int buffer[holder->height][holder->width], unsigned int x)
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
			buffer[var][x] = get_pixel(holder->camera->texture[4], \
							FLOOR_TEX_X >> 1, FLOOR_TEX_Y);
			if (holder->shadows)
				buffer[var][x] = alter_color_fixed(buffer[var][x],\
				(int)((float)current[0] * 256) / 10);
		}
	}
}

void			draw_floor1(t_wolf *holder, unsigned int buffer[holder->height][holder->width], unsigned int x)
{
	int		i;
	float	current[3];
	float	weight;
	float	old_wall_height;
	float	new_wall_height = holder->wall_height;

	i = holder->height;
	holder->state = 0;
	while (--i > holder->camera->draw_end)
	{
		current[0] = FIXED_F(FIX_DIV(INT_F(holder->height),	INT_F((i << 1) - holder->height - 2 * (holder->updown + holder->extra_updown - holder->wall_height))));
		weight = current[0] / PERP_DIST_WALL;
		current[1] = weight * WALL_X_FL + (1.0 - weight) * P_X;
		current[1] = (fabsf(current[1]) < 1) ? 1 : current[1];
		current[2] = weight * WALL_Y_FL + (1.0 - weight) * P_Y;
		if (current[1] <= 0 || current[2] < 0)
			continue;
		current[2] = (current[2] > 8) ? 8 : current[2];
		holder->wall_height = (holder->height_map[(int)current[2]][(int)current[1] - 1] > 300) ? 300 / current[0] : holder->height_map[(int)current[2]][(int)current[1] - 1] / current[0];
		old_wall_height = new_wall_height;
		new_wall_height = holder->height_map[(int)current[2]][(int)current[1] - 1];
		if (old_wall_height != new_wall_height)
			holder->state = !holder->state;
		if (!holder->state)
			buffer[i][x] = get_pixel(holder->camera->texture[4], FLOOR_TEX_X >> 1, FLOOR_TEX_Y);
		else
		{
			holder->state = !holder->state;
			buffer[i][x] = -1677721;
		}
		if (holder->shadows)
			buffer[i][x] = alter_color_fixed(buffer[i][x], (int)((float)current[0] * 256) / 10);
	}
}
