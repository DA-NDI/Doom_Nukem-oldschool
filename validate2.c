/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:39:23 by azulbukh          #+#    #+#             */
/*   Updated: 2018/10/23 23:55:45 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

#define BGD map[i][j] != 'B' && map[i][j] != 'G' && map[i][j] != 'D'

int		check_dimensions_and_symbols(char **map, int height, int width)
{
	int		i;
	int		j;
	int		dot;

	dot = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				dot++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' &&\
	map[i][j] != '\0' && map[i][j] != '3' && map[i][j] != 'P' && map[i][j]
	!= '4' && map[i][j] != '5' && map[i][j] != 'A' && map[i][j] != 'C' &&
	map[i][j] != '7' && map[i][j] != '8' && map[i][j] != '9' && map[i][j] !=
	'6' && map[i][j] != ':' && map[i][j] != ';' && map[i][j] != 'K' && map[i][j]
	!= 'H' && map[i][j] != 'S' && BGD)
				return (1);
		}
		if (j != width && (map[i][0] != '\0' || map[i][j] != '\0'))
			return (1);
	}
	return (i != height || !dot) ? 1 : 0;
}

void	check_amount(char **map, int i, int j)
{
	int		cars;
	int		arcades;
	int		ammo;

	cars = 0;
	arcades = 0;
	ammo = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				cars++;
			else if (map[i][j] == 'A')
				arcades++;
			else if (map[i][j] == 'G')
				ammo++;
		}
	}
	if (cars > 3 || arcades > 5 || ammo > 4)
		ft_print_error("Too many sprites!");
}

int		check_boundaries(char **map, int height)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j] && map[height - 1][j])
		if ((map[i][j] != '1' || map[height - 1][j++]
	!= '1') && (map[i][j] != ':' || map[height - 1][j++] != ':'))
			return (1);
	j = 0;
	while (++i < height)
	{
		if (map[i][j] != '1' && map[i][j] != ':')
			return (1);
		while (map[i][j++])
			;
		if (map[i][j - 2] != '1' && map[i][j - 2] != ':')
			return (1);
		j = 0;
	}
	if (map[i][j] != '\0')
		return (1);
	return (0);
}

void	ft_verify_map(char **map, t_wolf *holder)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!map || map[0][0] == '\n' || map[0][0] != '1')
		ft_print_error("Map error");
	while (map[i] != '\0')
		i++;
	while (map[0][j] != '\0')
		j++;
	holder->map_width = j - 1;
	holder->map_height = i - 2;
	if (i < 3 || j < 3)
		ft_print_error("Map is too small");
	if (j > 50)
		ft_print_error("Map is too wide");
	if (check_boundaries(map, i - 1))
		ft_print_error("Boundaries error. Should be all '1'");
	if (check_dimensions_and_symbols(map, i - 1, j))
		ft_print_error("Map dimensions or allowed symbols error");
}

void	fill_map(t_tool *tool, int *height_map[50])
{
	tool->splitted = ft_strsplit(tool->buff_height[tool->i], ' ');
	tool->a = -1;
	while (tool->splitted[++tool->a])
	{
		height_map[tool->i][tool->a] = ft_atoi(tool->splitted[tool->a]);
		height_map[tool->i][tool->a] = (height_map[tool->i][tool->a] >
		300) ? 300 : height_map[tool->i][tool->a];
		free(tool->splitted[tool->a]);
	}
	free(tool->splitted);
	free(tool->buff_height[tool->i]);
}
