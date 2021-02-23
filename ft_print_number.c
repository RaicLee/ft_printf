/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:09:42 by jealee            #+#    #+#             */
/*   Updated: 2021/02/23 14:51:32 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(unsigned long long nbr, t_info *block)
{
	char	*buffer;
	int		len;
	int		result;

	if (block->t == 'x' || block->t == 'X' || block->t == 'p')
		block->b = 16;
	if ((block->t == 'd' || block->t == 'i') && ((int)nbr < 0))
	{
		block->s = -1;
		nbr = -nbr;
	}
}
