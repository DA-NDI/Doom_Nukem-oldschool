/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_azap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:58:32 by azaporoz          #+#    #+#             */
/*   Updated: 2018/10/22 21:58:33 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int get_line_intersection(double p0_x, double p0_y, double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y, double *i_x, double *i_y)
{
	double s1_x, s1_y, s2_x, s2_y;
	s1_x = p1_x - p0_x;
	s1_y = p1_y - p0_y;

	s2_x = p3_x - p2_x;
	s2_y = p3_y - p2_y;

	double s, t;
	s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);
	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		if (i_x != NULL)
			*i_x = p0_x + (t * s1_x);
		if (i_y != NULL)
			*i_y = p0_y + (t * s1_y);
		return 1;
	}
	return 0;
}


t_mouse lineLineIntersection(t_lines a, t_lines b)
{
    double a1 = a.y2 - a.y1;
    double b1 = a.x1 - a.x2;
    double c1 = a1 * (a.x1) + b1 * (a.y1);
    double a2 = b.y2 - b.y1;
    double b2 = b.x1 - b.x2;
    double c2 = a2 * (b.x1) + b2 * (b.y1);
    double determinant = a1*b2 - a2*b1;

	t_mouse		res;

	if (determinant == 0)
	{
		res.x = 0;
		res.y = 0;
		return (res);
	}
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
		res.x = x;
		res.y = y;
        return (res);
    }
}









void			draw_walls_azap(t_wolf *holder, t_camera *camera, \
					unsigned int buffer[holder->height][holder->width], unsigned int x)
{
	int				tex_n;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
	float flooor;

	float draw_end = HEIGHT / 2 + (POLY_H >> 1) + holder->updown + holder->extra_updown; //y0
	float draw_start = HEIGHT / 2 - (POLY_H >> 1) + holder->updown + holder->extra_updown;	//y1	
	draw_start = (draw_start < 0) ? 0 : draw_start;
	if (draw_end >= holder->height)
	{
		flooor = draw_end;
		draw_end = holder->height - 1;
	}
	while (++draw_start < draw_end)
	{
		tex_y = (draw_start - HEIGHT / 2  + POLY_H / 2 - holder->updown - holder->extra_updown) * 64 / POLY_H;
		color = 4343523423;
		if (holder->shadows)
			color = alter_color_fixed(color, (int)((float)camera->perp_wall_dist * 256) / 10);
		if (camera->side == 1 && tex_n != 6)
			color = ((color & 0xfefefe) >> 1) | 0xFF000000;
		buffer[(int)draw_start][x] = color;
	}
}






float	ft_cos(float angle)
{
	printf("ANGLE::%f\n", angle);
	return (cos((angle * 2 * M_PI) / 360));
}



void	draw_lines(t_wolf *holder, unsigned int buffer[holder->height][holder->width], int x)
{
	int i;
	int height;
	// t_mouse res[3];
	t_mouse res;
	t_lines main_line;

	main_line.x1 = P_X;
	main_line.y1 = P_Y;
	main_line.x2 = holder->camera->map_x;
	main_line.y2 = holder->camera->map_y;

	i = 0;
	while (i < 3)
	{
		if (get_line_intersection(P_X, P_Y, holder->camera->wall_xx, holder->camera->wall_yy, holder->line[i].x1, holder->line[i].y1, holder->line[i].x2, holder->line[i].y2, NULL, NULL))
		{
			res = lineLineIntersection(main_line, holder->line[i]);
			// height = (camera->map_x - P_X + \ ((1 - camera->step_x) >> 1)) / camera->ray_dir_x;
			// (((int)sqrt(powf(win->gg.p_x - win->l_p.x, 2) + powf(win->gg.p_y - win->l_p.y, 2))) * ft_cos(win->gg.angle - angle));
			height = (((int)sqrt(powf(P_X - res.x, 2) + powf(P_Y - res.y, 2))) * ft_cos(atan2(holder->DIR_X, holder->DIR_Y) * (180 / 3.1415926)));
			draw_walls_azap(holder, holder->camera, buffer, x);
		}
		i++;
	}
}
