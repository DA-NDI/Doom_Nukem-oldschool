/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:01:47 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/06 22:20:55 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	long int	a;
	int			i;

	i = 0;
	a = (long int)n;
	if (a < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a < 10)
	{
		ft_putchar(a + '0');
		return ;
	}
	ft_putnbr(a / 10);
	ft_putchar((a % 10) + '0');
}
