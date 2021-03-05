/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:44:00 by jealee            #+#    #+#             */
/*   Updated: 2021/03/05 19:35:12 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_numstr(unsigned long long number, t_info *block, char **buf)
{
	int	len;
	int	result;
	int	i;

	len = ft_getnumlen(number, block);
	if (block->p > len)
		result = block->p;
	else
		result = len;
	*buf = (char *)malloc(sizeof(char) * (result + 1));
	if (!(*buf))
		return (0);
	i = 0;
	while (len + i < result)
	{
		(*buf)[i++] = '0';
	}
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

int	ft_add_minustr(t_info *block, char **buf)
{
	int	result;

	result = 0;
	if ((block->t == 'i' || block->t == 'd') && block->z == 0 && block->s == -1)
	{
		*buf = ft_join("-", *buf, 2);
		result = 1;
	}
	return (result);
}

int	ft_add_minustr2(int len, t_info *block, char **buf)
{
	int		result;

	result = 0;
	if (block->s == -1 && block->z == 1)
	{
		if (len >= block->w)
		{
			*buf = ft_join("-", *buf, 2);
			result++;
		}
		else
			*buf[0] = '-';
	}
	return (result);
}

int	ft_add_0x(char **buf)
{
	*buf = ft_join("0x", *buf, 2);
	return (2);
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
	len = ft_get_numstr(number, block, &buffer);
	len += ft_add_minustr(block, &buffer);
	if (block->t == 'p')
		len += ft_add_0x(&buffer);
	result = ft_s_width(&buffer, block);
	result += ft_add_minustr2(len, block, &buffer);
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
