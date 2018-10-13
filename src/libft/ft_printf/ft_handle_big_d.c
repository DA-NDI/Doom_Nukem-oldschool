/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_big_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:30:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/31 21:40:48 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_handle_big_d(t_field *placeholder, va_list *ap, int *len)
{
	placeholder->length = l;
	ft_print_d_i(placeholder, ap, len);
}
