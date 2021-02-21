/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:20:43 by jealee            #+#    #+#             */
/*   Updated: 2021/02/21 20:42:45 by jealee           ###   ########.fr       */
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
	
}
