/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:26:03 by jealee            #+#    #+#             */
/*   Updated: 2021/03/08 18:13:27 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ux(unsigned int number, t_info *block)
{
	int		len;
	char	*buffer;
	int		result;

	if (block->t == 'x' || block->t == 'X')
		block->b = 16;
	len = ft_get_num_id(number, block, &buffer);
	if (len < 0)
		return (-1);
	result = ft_s_width(&buffer, block);
	if (result < 0)
		return (-1);
	len = ft_add_minus_id2(len, block, &buffer);
	if (len < 0)
		return (-1);
	result += len;
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
