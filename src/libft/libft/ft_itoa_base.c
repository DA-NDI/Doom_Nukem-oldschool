/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:07:57 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 05:06:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	get_char(long n)
{
	if (n <= 9)
		return (n + '0');
	return (n - 10 + 'A');
}

static void	convert_number(long value, int base, char *str, int ssize)
{
	int		i;

	if (value == 0)
	{
		str[0] = '0';
		return ;
	}
	i = ssize - 1;
	while (value > 0)
	{
		str[i] = get_char(value % base);
		value /= base;
		i--;
	}
}

char		*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		stringsize;
	int		bonus;
	long	val;

	stringsize = ft_count_digits(value, base);
	bonus = value < 0 ? 1 : 0;
	ans = (char*)malloc(sizeof(char) * (stringsize + bonus + 1));
	val = value;
	val = val < 0 ? -val : val;
	ans[0] = value < 0 ? '-' : '0';
	convert_number(val, base, ans + bonus, stringsize);
	ans[stringsize + bonus] = '\0';
	return (ans);
}
