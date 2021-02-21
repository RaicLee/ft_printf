/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:20:43 by jealee            #+#    #+#             */
/*   Updated: 2021/02/21 21:14:10 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int toprint, t_info *block)
{
	int	result;

	result = 0;
	if (block->t == '%' && block->m == 1)
		block->z = 0;
	if (block->m == 1)
		result += ft_putchar(toprint);
	result += ft_char_width(block->w, 1, block->z);
	if (block->m == 0)
		result += ft_putchar(toprint);
	return (result);
}

int	ft_char_width(int width, int len, int zero)
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
