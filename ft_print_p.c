/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:25:02 by jealee            #+#    #+#             */
/*   Updated: 2021/03/05 21:57:53 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getnumlen_p(unsigned long long nbr, t_info *block)
{
	int	i;

	if (!nbr && block->p != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr = nbr / block->b;
		i++;
	}
	return (i);
}

int	ft_get_num_p(unsigned long long number, t_info *block, char **buf)
{
	int	len;
	int	result;
	int	i;

	len = ft_getnumlen_p(number, block);
	if (block->p > len)
		result = block->p;
	else
		result = len;
	if (!(*buf = (char *)malloc(sizeof(char) * (result + 1))))
		return (0);
	i = 0;
	while (len + i < result)
		(*buf)[i++] = '0';
	(*buf)[result] = '\0';
	i = 1;
	if (number == 0 && block->p != 0)
		(*buf)[result - i] = '0';
	while (number)
	{
		(*buf)[result - i] = ft_getbase(block->t)[number % block->b];
		number /= block->b;
		i++;
	}
	return (len);
}

int	ft_print_p(unsigned long long number, t_info *block)
{
	int				len;
	char			*buffer;
	int				result;

	block->b = 16;
	len = ft_get_num_p(number, block, &buffer);
	len += ft_add0x(&buffer);
	result = ft_s_width(&buffer, block);
	result += ft_add_minus_id2(len, block, &buffer);
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
