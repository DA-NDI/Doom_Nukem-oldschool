/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lelush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:25:18 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 20:45:05 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			add_head(t_global *global, t_line *cur)
{
	ft_putnbr_fd(cur->texture_number, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->x1, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->y1, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->x2, global->fd);
	ft_putstr_fd(" ", global->fd);
	ft_putnbr_fd(cur->y2, global->fd);
	ft_putstr_fd(" ", global->fd);
	if (abs(cur->height) > 300)
		ft_putnbr_fd(300, global->fd);
	else
		ft_putnbr_fd(abs(cur->height), global->fd);
	ft_putstr_fd("\n", global->fd);
}

void			push_fig(t_global *global, int i, int j)
{
	if (global->map[j][i] >> 16 == 6)
		ft_putstr_fd(";", global->fd);
	else if (global->map[j][i] >> 16 == 11)
		ft_putstr_fd("G", global->fd);
	else if (global->map[j][i] >> 16 == 12)
		ft_putstr_fd("A", global->fd);
	else if (global->map[j][i] >> 16 == 13)
		ft_putstr_fd("C", global->fd);
	else if (global->map[j][i] >> 16 == 14)
		ft_putstr_fd("K", global->fd);
	else if (global->map[j][i] >> 16 == 15)
		ft_putstr_fd("S", global->fd);
	else if (global->map[j][i] >> 16 == 16)
		ft_putstr_fd("H", global->fd);
	else
		ft_putchar_fd((char)(global->map[j][i] >> 16) + '0',
	global->fd);
}

void			push_cord(t_global *global)
{
	int i;
	int j;
	int q;

	i = -1;
	q = 0;
	while (++i < global->mode)
	{
		j = -1;
		while (++j < global->mode)
		{
			if (global->map[j][i] >> 16 == 6 || global->map[j][i] >> 16 == 10)
				ft_putstr_fd(":", global->fd);
			else if ((i == 0 || i == global->mode - 1))
				ft_putstr_fd("1", global->fd);
			else if ((j == 0 || j == global->mode - 1))
				ft_putstr_fd("1", global->fd);
			else if ((global->map[j][i]) >> 16 <= 0 || (global->map[j][i]
			>> 16) > 16)
				if_it(global, &q);
			else
				push_fig(global, i, j);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

void			push_height(t_global *global)
{
	int i;
	int j;

	i = -1;
	ft_putstr_fd("Height map:\n", global->fd);
	while (++i < global->mode)
	{
		j = -1;
		while (++j < global->mode)
		{
			ft_putstr_fd("0", global->fd);
			ft_putstr_fd(" ", global->fd);
		}
		ft_putstr_fd("\n", global->fd);
	}
}

void			make_exit(t_line **lines, t_global *global)
{
	t_line	*cur;

	cur = *lines;
	if (cur)
	{
		ft_putnbr_fd(number_of_lines(cur), global->fd);
		ft_putstr_fd(" ", global->fd);
		ft_putnbr_fd(global->mode, global->fd);
		ft_putstr_fd("\n", global->fd);
	}
	while (cur)
	{
		add_head(global, cur);
		cur = cur->next;
	}
	ft_putstr_fd("\n", global->fd);
	push_cord(global);
	ft_putstr_fd("\n", global->fd);
	push_height(global);
}
