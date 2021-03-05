/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:29:48 by jealee            #+#    #+#             */
/*   Updated: 2021/03/05 19:34:46 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int toprint, t_info *block)
{
	int	result;

	result = 0;
	if (block->t == '%' && block->m == 1)
		block->z = 0;
	if (block->m == 1)
		result += ft_putchar(toprint);
	result += ft_c_width(block->w, 1, block->z);
	if (block->m == 0)
		result += ft_putchar(toprint);
	return (result);
}

int	ft_c_width(int width, int len, int zero)
{
	int result;

	result = 0;
	while (len < width)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		result++;
	}
	return (result);
}
