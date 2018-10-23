/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:34:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/23 14:34:37 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	check_ray(t_camera *camera, t_wolf *holder)
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

void	check_hit_2(t_camera *camera, t_wolf *holder)
{
	holder->wall_height = (camera->map_y > 0 && camera->map_x > 0) ?\
	holder->height_map[camera->map_y - 1][camera->map_x - 1] : \
		holder->height_map[0][0];
	holder->wall_height = (camera->map_y > 0 && camera->map_x == 0) ?\
	holder->height_map[camera->map_y - 1][0] : \
		holder->height_map[0][camera->map_x - 1];
}

void	check_hit(t_camera *camera, t_wolf *holder)
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
}
