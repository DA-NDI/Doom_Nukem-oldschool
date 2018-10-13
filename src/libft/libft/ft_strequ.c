/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:08:57 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/12 16:54:30 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	j = 0;
	i = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if ((ft_strlen(s1) == ft_strlen(s2) && (s1[i] - s2[j]) == 0))
		return (1);
	else
		return (0);
}
