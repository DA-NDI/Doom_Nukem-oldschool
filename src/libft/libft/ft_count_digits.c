/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:06:38 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 05:07:02 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_digits(int value, int base)
{
	long	temp;
	int		ans;

	temp = value;
	temp = temp < 0 ? -temp : temp;
	ans = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		ans++;
		temp /= base;
	}
	return (ans);
}
