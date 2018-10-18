/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:01:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 15:52:50 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

void			check_ray(t_camera *camera, t_wolf *holder)
{
	if (camera->ray_dir_x < 0)
	{
		camera->step_x = -1;
		camera->side_dist_x = (P_X - camera->map_x) * DELTA_DIST_X;
	}
	else
	{
		camera->step_x = 1;
		camera->side_dist_x = (camera->map_x + 1.0 - P_X) * DELTA_DIST_X;
	}
	if (camera->ray_dir_y < 0)
	{
		camera->step_y = -1;
		camera->side_dist_y = (P_Y - camera->map_y) * DELTA_DIST_Y;
	}
	else
	{
		camera->step_y = 1;
		camera->side_dist_y = (camera->map_y + 1.0 - P_Y) * DELTA_DIST_Y;
	}
}

void			check_hit(t_camera *camera, t_wolf *holder)
{
	while (camera->is_hit == 0)
	{
		if (camera->side_dist_x < camera->side_dist_y)
		{
			camera->side_dist_x += DELTA_DIST_X;
			camera->map_x += camera->step_x;
			camera->side = 0;
		}
		else
		{
			camera->side_dist_y += DELTA_DIST_Y;
			camera->map_y += camera->step_y;
			camera->side = 1;
		}
		if (MAP[camera->map_y][camera->map_x] > '0')
			camera->is_hit = 1;
	}
	if (camera->side == 0)
		camera->perp_wall_dist = (camera->map_x - P_X + \
							((1 - camera->step_x) >> 1)) / camera->ray_dir_x;
	else
		camera->perp_wall_dist = (camera->map_y - P_Y + \
							((1 - camera->step_y) >> 1)) / camera->ray_dir_y;
	holder->wall_height = (camera->map_y > 0 && camera->map_x > 0) ? holder->height_map[camera->map_y - 1][camera->map_x - 1] : \
		holder->height_map[0][0];
	holder->wall_height = (camera->map_y > 0 && camera->map_x == 0) ? holder->height_map[camera->map_y - 1][0] : \
		holder->height_map[0][camera->map_x - 1];		

}

void			draw_walls(t_wolf *holder, t_camera *camera, \
					unsigned int buffer[][holder->width], unsigned int x)
{
	int				tex_n;
	int				tex_x;
	int				tex_y;
	unsigned int	color;


//	holder->updown = (hodler->current_height == )
	if (x == 500)
	{
//		printf("camera->map_x = %d, camera->map_y = %d\n", camera->map_x, camera->map_y);
//		printf("holder->wall_height == %d\n", holder->height_map[camera->map_y][camera->map_x]);
	}
	holder->wall_height = holder->wall_height / camera->perp_wall_dist;
	camera->draw_end = HEIGHT / 2 + (LINE_H >> 1) + holder->updown + holder->extra_updown - holder->wall_height; //y0
	camera->draw_start = HEIGHT / 2 - (LINE_H >> 1) + holder->updown + holder->extra_updown - holder->wall_height;	//y1	
	camera->draw_start = (camera->draw_start < 0) ? 0 : camera->draw_start;
//	printf("camera->draw_end = %d, camera->draw_start = %d\n", camera->draw_end, camera->draw_start);
	if (camera->draw_end >= holder->height)
		camera->draw_end = holder->height - 1;
	tex_n = (MAP_CELL != 'P') ? MAP_CELL - '1' : 0;
	tex_x = (int)(camera->wall_x * 64);
	tex_x = (CHECK_SIDE_0 || CHECK_SIDE_1) ? 64 - tex_x - 1 : tex_x;
	while (++camera->draw_start < camera->draw_end)
	{
		tex_y = (DR_START - HEIGHT / 2  + LINE_H / 2 - holder->updown - holder->extra_updown + holder->wall_height) * 64 / LINE_H;
		color = get_pixel(camera->texture[tex_n], tex_x, tex_y);
//		if (holder->shadows)
//			color = alter_color(color, camera->perp_wall_dist / 10);
		if (holder->shadows)
			color = alter_color_fixed(color, (int)((float)camera->perp_wall_dist * 256) / 10);
		if (camera->side == 1 && tex_n != 6)
			color = ((color & 0xfefefe) >> 1) | 0xFF000000;
		color = (tex_n == 0 ) ? color << 1 >> 1 : color;
		color >>= (CHECK_SIDE_0 && tex_n == 6) ? 1 : 0;
		color |= (CHECK_SIDE_3 && tex_n == 6) ? 0xFF00F00F : 0;
		color |= (CHECK_SIDE_2 && tex_n == 6) ? 0xFFF00000 : 0;

		buffer[camera->draw_start][x] = color;
	}
}

void			raycasting_loop(t_wolf *holder, t_camera *camera, int x, \
								unsigned int buffer[][holder->width])
{

	while (++x < holder->width)
	{
		camera->camera_x = (float)((x << 1) / (float)(holder->width) - 1);
		camera->ray_dir_x = DIR_X + PLANE_X * camera->camera_x;
		camera->ray_dir_y = DIR_Y + camera->plane_y * camera->camera_x;
		camera->map_x = (int)P_X;
		camera->map_y = (int)P_Y;
		DELTA_DIST_X = fabs(1 / camera->ray_dir_x);
		DELTA_DIST_Y = fabs(1 / camera->ray_dir_y);
		camera->is_hit = 0;
		
		check_ray(camera, holder);
		check_hit(camera, holder);
		LINE_H = (int)(holder->height / camera->perp_wall_dist);
		if (camera->side == 0)
			camera->wall_x = P_Y + camera->perp_wall_dist * camera->ray_dir_y;
		else
			camera->wall_x = P_X + camera->perp_wall_dist * camera->ray_dir_x;
		camera->wall_x -= floor((camera->wall_x));
		holder->zbuffer[x] = camera->perp_wall_dist;
		draw_walls(holder, camera, buffer, x);
		draw_floor(holder, camera, buffer, x);
	}
}

void			ft_raycasting(t_wolf *holder, int x)
{
	unsigned int	buffer[holder->height][holder->width];
	static int		i = 0;

	while (holder->running)
	{
		holder->frame_start = SDL_GetTicks();
		holder->current_height = holder->height_map[(int)P_Y][(int)P_X];
		holder->current_height = (holder->current_height > 300) ? 300 : holder->current_height;
		raycasting_loop(holder, holder->camera, -1, buffer);
//		printf("current_height = %d\n", holder->current_height);
		ft_draw_sprites(holder, holder->camera, buffer);
		if ((++i % 16) == 0)
			ft_move_boss(holder, holder->sprite);
		if (!holder->pause && !holder->starting)
		{
			SDL_UpdateTexture(holder->screen, NULL, buffer[0], WIDTH << 2);
			x = -1;
			while (++x < holder->height)
				ft_zero_fill(buffer[x], holder->width);
			SDL_RenderClear(holder->renderer);
			draw_skybox(holder, holder->camera);
			SDL_RenderCopy(holder->renderer, holder->screen, NULL, NULL);
			draw_weapon(holder->weapon, holder);
			draw_fps(holder, holder->camera->font);
			draw_hud(holder);
			SDL_RenderPresent(holder->renderer);
		}
		ft_close_loop(holder, holder->camera);
	}
}
