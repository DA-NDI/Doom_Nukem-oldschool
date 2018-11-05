/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_azap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:47:49 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 12:51:54 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#define LINE_Y1 holder->line[i].y1

int		get_line_intersection1(t_wolf *holder, double *i_x, double *i_y, int i)
{
	double	s1_x;
	double	s1_y;
	double	s2_x;
	double	s2_y;
	double	s;

	s1_x = WALL_X_FL - P_X;
	s1_y = WALL_Y_FL - P_Y;
	s2_x = holder->line[i].x2 - holder->line[i].x1;
	s2_y = holder->line[i].y2 - holder->line[i].y1;
	s = (-s1_y * (P_X - holder->line[i].x1) + s1_x * (P_Y - LINE_Y1)) / \
		(-s2_x * s1_y + s1_x * s2_y);
	holder->tmp = (s2_x * (P_Y - LINE_Y1) - s2_y * (P_X - \
	holder->line[i].x1)) / (-s2_x * s1_y + s1_x * s2_y);
	if (s >= 0 && s <= 1 && holder->tmp >= 0 && holder->tmp <= 1)
	{
		if (i_x != NULL)
			*i_x = P_X + (holder->tmp * s1_x);
		if (i_y != NULL)
			*i_y = P_Y + (holder->tmp * s1_y);
		return (1);
	}
	return (0);
}

t_mouse	line_line_intersection(t_lines a, t_lines b, double inter[6], double x)
{
	double		determinant;
	t_mouse		res;
	double		y;

	inter[0] = a.y2 - a.y1;
	inter[1] = a.x1 - a.x2;
	inter[2] = inter[0] * (a.x1) + inter[1] * (a.y1);
	inter[3] = b.y2 - b.y1;
	inter[4] = b.x1 - b.x2;
	inter[5] = inter[3] * (b.x1) + inter[4] * (b.y1);
	determinant = inter[0] * inter[4] - inter[3] * inter[1];
	if (determinant == 0)
	{
		res.x = 0;
		res.y = 0;
		return (res);
	}
	else
	{
		x = (inter[4] * inter[2] - inter[1] * inter[5]) / determinant;
		y = (inter[0] * inter[5] - inter[3] * inter[2]) / determinant;
		res.x = x;
		res.y = y;
		return (res);
	}
}

void	draw_walls_azap(t_wolf *holder, t_camera *camera, \
								unsigned int *buffer, unsigned int x)
{
	unsigned int	color;
	float			flooor;
	float			draw_end;
	float			draw_start;

	draw_end = (HEIGHT + POLY_H) / 2 + holder->updown + holder->extra_updown;
	draw_start = (HEIGHT - POLY_H) / 2 + holder->updown + holder->extra_updown;
	draw_start = (draw_start < 0) ? 0 : draw_start;
	if (draw_end >= holder->height)
	{
		flooor = draw_end;
		draw_end = holder->height - 1;
	}
	while (++draw_start < draw_end)
	{
		color = buffer[(int)draw_start * 1024 + x];
		if (holder->shadows)
			color = alter_color_fixed(color, POLY_H * 1024);
		buffer[(int)draw_start * 1024 + x] = (color << 1 >> 1) + 100;
	}
}

float	ft_cos(float angle)
{
	return (cos((angle * 2 * M_PI) / 360));
}

void	draw_lines(t_wolf *holder, unsigned int *buffer, unsigned int x, int i)
{
	t_mouse	res;
	t_lines	main_line;
	float	angle;
	double	arr[6];

	main_line.x1 = P_X;
	main_line.y1 = P_Y;
	main_line.x2 = holder->camera->wall_x_f;
	main_line.y2 = holder->camera->wall_y_f;
	while (i < 3)
	{
		if (get_line_intersection1(holder, NULL, NULL, i))
		{
			res = line_line_intersection(main_line, holder->line[i], arr, 0.0);
			angle = atan2(holder->DIR_Y, holder->DIR_X) * (180 / 3.1415926);
			holder->POLY_H = 1024.0 / (float)sqrt(powf(P_X - res.x, 2) + \
				powf(P_Y - res.y, 2));
			draw_walls_azap(holder, holder->camera, buffer, x);
		}
		i++;
	}
}
