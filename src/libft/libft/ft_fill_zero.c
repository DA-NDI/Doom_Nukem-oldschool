/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:29:23 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/15 19:38:36 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_zero_fill(unsigned int *s, size_t n)
{
	unsigned int	*copy_s;

	copy_s = s;
	if (n == 0)
		return ;
	while (n--)
		*copy_s++ = 0;
}
