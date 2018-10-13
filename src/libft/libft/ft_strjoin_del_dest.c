/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del_dest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:00:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/31 21:46:00 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_del_dest(char *dest, char *src)
{
	char	*s;

	s = ft_strjoin(dest, src);
	ft_strdel(&dest);
	return (s);
}
