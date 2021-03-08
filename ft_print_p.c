/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:25:02 by jealee            #+#    #+#             */
/*   Updated: 2021/03/08 22:18:40 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_add0x(char **buf)
{
	*buf = ft_join("0x", *buf, 2);
	if (*buf == NULL)
		return (-1);
	return (2);
}

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

int		ft_get_num_p(unsigned long long number, t_info *block, char **buf)
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
		return (-1);
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

int		ft_print_p(unsigned long long number, t_info *block)
{
	int		len;
	char	*buffer;
	int		result;
	int		temp;

	block->b = 16;
	if ((len = ft_get_num_p(number, block, &buffer)) < 0)
		return (-1);
	if ((temp = ft_add0x(&buffer)) < 0)
		return (-1);
	len += temp;
	if ((result = ft_s_width(&buffer, block)) < 0)
	{
		if (buffer)
			free(buffer);
		return (-1);
	}
	if ((len = ft_add_minus_id2(len, block, &buffer)) < 0)
		return (-1);
	result += len;
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
