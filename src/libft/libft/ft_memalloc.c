/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:59:13 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/01 14:16:25 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	size_t	*mem;

	if (!(mem = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	else
		ft_memset(mem, 0, size);
	return (mem);
}
