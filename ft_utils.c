/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:18:52 by jealee            #+#    #+#             */
/*   Updated: 2021/02/18 16:30:12 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	block_initialize(t_info *block)
{
	block->minus = 0;
	block->zero = 0;
	block->width = 0;
	block->precision = -1;
	block->type = 0;
	block->base_num = 10;
	block->sign_num = 1;
}
