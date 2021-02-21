/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:18:52 by jealee            #+#    #+#             */
/*   Updated: 2021/02/21 20:57:34 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	block_initialize(t_info *block)
{
	block->m = 0;
	block->z = 0;
	block->w = 0;
	block->p = -1;
	block->t = 0;
	block->b = 10;
	block->s = 1;
}

int		ft_putchar(char ch)
{
	return (write(1, &ch, sizeof(char)));
}

int		ft_chartoint(char ch)
{
	return (ch - '0');
}
