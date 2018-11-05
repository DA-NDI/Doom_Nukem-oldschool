/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting__drawing_sprites.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:32:00 by avolgin           #+#    #+#             */
/*   Updated: 2018/10/27 22:48:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_swap_i(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_f(float *a, float *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_sprite1(int gap, int num, int *order, float *dist)
{
	int		swapped;
	int		i;
	int		j;

	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		i = -1;
		while (++i < num - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap_f(&dist[i], &dist[j]);
				ft_swap_i(&order[i], &order[j]);
				swapped = 1;
			}
		}
	}
}

void	ft_sort_sprite(t_wolf *holder, t_sprite **sprites, int i, int num)
{
	int		gap;
	int		swapped;

	gap = num;
	swapped = 0;
	while (++i < num)
	{
		holder->sprites->order[i] = i;
		holder->sprites->dist[i] = ((P_X - sprites[i]->x) * \
			(P_X - sprites[i]->x) + (P_Y	\
		- sprites[i]->y) * (P_Y - sprites[i]->y));
		sprites[i]->distance = holder->sprites->dist[i];
	}
	ft_sort_sprite1(gap, num, holder->sprites->order, holder->sprites->dist);
}

void	drawing_sorting_sprites(t_wolf *holder, t_sprite **sprites, int num, \
unsigned int *buffer)
{
	int			i;
	static int	a = 0;

	i = -1;
	ft_sort_sprite(holder, sprites, -1, num);
	a++;
	ft_draw_sprites(holder, holder->camera, buffer, holder->sprite[0]);
	while (++i < num)
		ft_draw_sprites(holder, holder->camera, buffer, \
						sprites[holder->sprites->order[i]]);
	ft_check_pickups(holder, -1);
}
