/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:02:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/09/28 19:57:09 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			draw_score(t_wolf *holder)
{
	char		*fps;
	char		*tmp;

	fps = ft_itoa(holder->frags * 10);
	tmp = fps;
	fps = ft_strjoin("Score: ", fps);
	free(tmp);
	draw_text(holder, fps, 45, 20);
	free(fps);
}
