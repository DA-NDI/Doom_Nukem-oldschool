/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_loop_draw_walls.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:12:54 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/23 15:12:54 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

void	draw_walls_2(t_wolf *holder, t_camera *camera,\
unsigned int buffer[holder->height][holder->width], int tex[4])
{
	unsigned int	color;

	while (++camera->draw_start < camera->draw_end)
	{
		tex[2] = (DR_START - HEIGHT / 2 + LINE_H / 2 - holder->updown - \
		holder->extra_updown + holder->wall_height) * 64 / LINE_H;
		color = get_pixel(camera->texture[tex[0]], tex[1], tex[2]);
		if (holder->shadows)
			color = alter_color_fixed(color,\
			(int)((float)camera->perp_wall_dist * 256) / 10);
		if (camera->side == 1 && tex[0] != 6)
			color = ((color & 0xfefefe) >> 1) | 0xFF000000;
		color = (tex[0] == 0) ? color << 1 >> 1 : color;
		color >>= (CHECK_SIDE_0 && tex[0] == 6) ? 1 : 0;
		color |= (CHECK_SIDE_3 && tex[0] == 6) ? 0xFF00F00F : 0;
		color |= (CHECK_SIDE_2 && tex[0] == 6) ? 0xFFF00000 : 0;
		buffer[camera->draw_start][tex[3]] = color;
	}
}

void	draw_walls(t_wolf *holder, t_camera *camera, \
unsigned int buffer[holder->height][holder->width], unsigned int x)
{
	int tex[4];

	holder->wall_height = holder->wall_height / camera->perp_wall_dist;
	camera->draw_end = HEIGHT / 2 + (LINE_H >> 1) + holder->updown + \
	holder->extra_updown - holder->wall_height;
	camera->draw_start = HEIGHT / 2 - (LINE_H >> 1) + holder->updown + \
	holder->extra_updown - holder->wall_height;
	camera->draw_start = (camera->draw_start < 0) ? 0 : camera->draw_start;
	if (camera->draw_end >= holder->height)
	{
		camera->floor = camera->draw_end;
		camera->draw_end = holder->height - 1;
	}
	tex[0] = (MAP_CELL != 'P' && MAP_CELL != 'C' && MAP_CELL != 'A') ?\
	MAP_CELL - '1' : 0;
	tex[1] = (int)(camera->wall_x * 64);
	tex[1] = (CHECK_SIDE_0 || CHECK_SIDE_1) ? 64 - tex[1] - 1 : tex[1];
	tex[3] = x;
	draw_walls_2(holder, camera, buffer, tex);
}

void	raycasting_loop_2(t_wolf *holder, t_camera *camera, int x)
{
	camera->camera_x = (float)((x << 1) / (float)(holder->width) - 1);
	camera->ray_dir_x = DIR_X + PLANE_X * camera->camera_x;
	camera->ray_dir_y = DIR_Y + camera->plane_y * camera->camera_x;
	camera->map_x = (int)P_X;
	camera->map_y = (int)P_Y;
	DELTA_DIST_X = fabs(1 / camera->ray_dir_x);
	DELTA_DIST_Y = fabs(1 / camera->ray_dir_y);
	camera->is_hit = 0;
}

void	raycasting_loop(t_wolf *holder, t_camera *camera, int x,\
unsigned int buffer[holder->height][holder->width])
{
	while (++x < holder->width)
	{
		raycasting_loop_2(holder, camera, x);
		check_ray(camera, holder);
		check_hit(camera, holder);
		LINE_H = (int)(holder->height / camera->perp_wall_dist);
		if (camera->side == 0)
			camera->wall_x = P_Y + camera->perp_wall_dist * camera->ray_dir_y;
		else
			camera->wall_x = P_X + camera->perp_wall_dist * camera->ray_dir_x;
		camera->wall_xx = P_Y + camera->perp_wall_dist * camera->ray_dir_y;
		camera->wall_yy = P_X + camera->perp_wall_dist * camera->ray_dir_y;
		camera->wall_x -= floor((camera->wall_x));
		holder->zbuffer[x] = camera->perp_wall_dist;
		draw_walls(holder, camera, buffer, x);
		draw_floor(holder, camera, buffer, x);
	}
}
