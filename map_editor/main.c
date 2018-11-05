/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:35:47 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/27 23:45:08 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			if_it(t_global *global, int *q)
{
	if (!(*q))
	{
		ft_putstr_fd("P", global->fd);
		*q = 1;
	}
	else
		ft_putstr_fd("0", global->fd);
}

void			global_pos_26(t_global *global)
{
	global_pos_2_write(global);
}

void			global_pos_3(t_global *global)
{
	global_pos_3_edit(global);
}

int				main(int ac, char **av)
{
	t_global global;

	if (ac == 4)
		ac_4(&global, av);
	else
	{
		ft_putstr("Usage: ./map [grid size] [-n || -e] [filename]\n");
		return (0);
	}
	set_global_mode(&global);
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		init_sdl(&global);
		loop(global);
		if (global.renderer)
			SDL_DestroyRenderer(global.renderer);
		if (global.window)
			SDL_DestroyWindow(global.window);
	}
	TTF_Quit();
	SDL_Quit();
	system("cd ../ && tar -cf package ./maps ./resourses \
			./sprites ./textures ./texture");
	return (0);
}
