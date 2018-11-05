/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:56:03 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/27 23:27:27 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		**ft_create_height_map(int fd)
{
	t_tool		tool;
	static int	*height_map[51];

	tool.i = 0;
	while (get_next_line(fd, &tool.buff) == 1)
	{
		if (ft_strlen(tool.buff) > 100 || tool.i >= 100)
		{
			free(tool.buff);
			ft_print_error("map is too big!");
		}
		tool.buff_height[tool.i++] = tool.buff;
	}
	tool.buff_height[tool.i] = NULL;
	tool.i = -1;
	while (tool.buff_height[++tool.i])
	{
		height_map[tool.i] = (int*)malloc(sizeof(int)
		* ft_strlen(tool.buff_height[tool.i]));
		fill_map(&tool, height_map);
	}
	height_map[tool.i] = NULL;
	return (height_map);
}
