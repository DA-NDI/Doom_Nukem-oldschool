/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:51:06 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/18 17:23:48 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	get_player_coordinates(t_wolf *holder)
{
	int		i;
	int		j;
	int		is_player;

	is_player = 0;
	i = -1;
	while (holder->map[++i])
	{
		j = -1;
		while (holder->map[i][++j])
		{
			if (holder->map[i][j] == 'P')
			{
				holder->player_x = (j == 1) ? 1.5 : j + 0.5;
				holder->player_y = (i == 1) ? 1.5 : i + 0.5;
				holder->current_height = holder->height_map[i][j];
				holder->map[i][j] = '0';
				is_player++;
			}
		}
	}
	if (is_player > 1 || !is_player)
		ft_print_error("Player coords error!");
}

int		get_sprite_coordinates(t_wolf *holder, char c)
{
	int		i;
	int		j;

	holder->sprite->is_alive = 0;
	holder->sprite->sprite_found = 0;
	i = -1;
	while (holder->map[++i])
	{
		j = -1;
		while (holder->map[i][++j])
		{
			if (holder->map[i][j] == c)
			{
				holder->sprite->x = (j == 1) ? 1.5 : j - 0.5;
				holder->sprite->orig_x = holder->sprite->x;
				holder->sprite->y = (i == 1) ? 1.5 : i - 0.5;
				holder->sprite->orig_y = holder->sprite->y;
				holder->map[i][j] = '0';
				holder->sprite->is_alive++;
				holder->sprite->is_sprite = 1;
				holder->sprite->sprite_found = 1;
			}
		}
	}
	return (holder->sprite->is_alive != 1) ? 0 : 1;
}
