/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kakuzu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:54 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:41:20 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				in_save_to_file(int x, int y)
{
	if (x > 1375 && y > 775 && x <= 1750 && y <= 875)
		return (1);
	else
		return (0);
}

int				dot_in_tex(int x, int y, t_global global, t_tools ij)
{
	if ((x > (ij.y * global.ymode)) && (y > (ij.x * global.xmode))
		&& (x < (ij.y * global.ymode + global.ymode)) && y <
		(ij.x * global.xmode + global.xmode))
	{
		return (1);
	}
	return (0);
}

int				chech_for_dot(t_line *cur, t_tools ij, t_global *global)
{
	float	t;
	int		x;
	int		y;

	while (cur)
	{
		t = 0;
		while (t < 1)
		{
			x = cur->x1 * (1. - t) + cur->x2 * t;
			y = cur->y1 * (1. - t) + cur->y2 * t;
			if (dot_in_tex(x, y, *global, ij) == 1)
				return (cur->texture_number);
			t += .01;
		}
		cur = cur->next;
	}
	return (-1);
}

void			push_tex_map(t_line **lines, t_global *global)
{
	t_line	*cur;
	int		g;
	t_tools	ij;

	ij.x = 0;
	cur = *lines;
	g = 0;
	while (++ij.x <= global->mode)
	{
		ij.y = 0;
		while (++ij.y <= global->mode)
		{
			cur = *lines;
			if ((g = chech_for_dot(cur, ij, global)) >= 0)
				ft_putnbr_fd(g, global->fd);
			else
				ft_putstr_fd(" ", global->fd);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

int				number_of_lines(t_line *cur)
{
	int		i;

	i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}
