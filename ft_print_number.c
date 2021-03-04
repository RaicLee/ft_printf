/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:44:00 by jealee            #+#    #+#             */
/*   Updated: 2021/03/03 23:52:15 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_numstr(unsigned long long number, t_info *block, char **buf)
{

}

int	ft_add_minustr(t_info *block, char **buf)
{

}

int	ft_add_0x(char **buf)
{

}

int	ft_print_number(unsigned long long number, t_info *block)
{
	int		len;
	char	*buffer;
	int		result;

	if (block->t == 'x' || block->t == 'X' || block->t == 'p')
		block->b = 16;
	if (block->t == 'd' || block->t == 'i')
	{
		if (number < 0)
		{
			number = -number;
			block->s = -1;
		}
	}
	len =  ft_get_numstr(number, block, &buffer);
	len += ft_add_minustr(block, &buffer);
	if (block->t == 'p')
		len += ft_add_0x(&buffer);
	return (result);
}
