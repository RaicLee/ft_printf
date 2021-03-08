/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:24:02 by jealee            #+#    #+#             */
/*   Updated: 2021/03/08 19:01:42 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getnumlen_id(unsigned int nbr, t_info *block)
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

int	ft_get_num_id(unsigned int number, t_info *block, char **buf)
{
	int	len;
	int	result;
	int	i;

	len = ft_getnumlen_id(number, block);
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

int	ft_add_minus_id(t_info *block, char **buf)
{
	int	result;

	result = 0;
	if (block->z == 0 && block->s == -1)
	{
		*buf = ft_join("-", *buf, 2);
		if (*buf == NULL)
			return (-1);
		result++;
	}
	return (result);
}

int	ft_add_minus_id2(int len, t_info *block, char **buf)
{
	int		result;

	result = 0;
	if (block->s == -1 && block->z == 1)
	{
		if (len >= block->w)
		{
			*buf = ft_join("-", *buf, 2);
			if (*buf == NULL)
				return (-1);
			result++;
		}
		else
			*buf[0] = '-';
	}
	return (result);
}

int	ft_print_id(int num, t_info *block)
{
	int				len;
	char			*buffer;
	int				result;
	unsigned int	number;
	int				temp;

	if (num < 0)
	{
		number = -num;
		block->s = -1;
	}
	else
		number = num;
	if ((len = ft_get_num_id(number, block, &buffer)) < 0)
		return (-1);
	if ((temp = ft_add_minus_id(block, &buffer)) < 0)
		return (-1);
	len += temp;
	if ((result = ft_s_width(&buffer, block)) < 0)
		return (-1);
	result += ft_add_minus_id2(len, block, &buffer);
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
