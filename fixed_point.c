/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:39:55 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/14 20:16:10 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		f_to_raw(float f)
{
	return (int)roundf(f * 256);
}

int		i_to_raw(int f)
{
	return (f << 8);
}

float	raw_to_f(int f)
{
	return (float)(f) / 256;
}

int		raw_to_i(int f)
{
	return (f >> 8);
}
