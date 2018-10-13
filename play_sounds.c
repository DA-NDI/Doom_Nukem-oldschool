/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:29:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/14 21:29:10 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	play_pistol(t_wolf *holder)
{
	Mix_Chunk *pistol_shoot;

	if (!(pistol_shoot = Mix_LoadWAV("resourses/pistol_plasma.wav")))
		ft_print_error("Failed to load pistol sound effect!");
}
