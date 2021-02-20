/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:20:43 by jealee            #+#    #+#             */
/*   Updated: 2021/02/20 23:23:02 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int toprint, t_info *block)
{
	int	result;

	result = 0;
	if (block->type == '%' && block->minus == 1)
		block->zero = 0;
	if (block->minus == 1)
		result += ft_putchar(toprint);
	resul
}
