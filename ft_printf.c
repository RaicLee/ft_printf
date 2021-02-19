/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:08:26 by jealee            #+#    #+#             */
/*   Updated: 2021/02/19 20:52:41 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_and_prec(va_list ap, char *format, t_info *block, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (block->precision == -1)
			block->width = block->width * 10 + ft_chartoint(format[i]);
		else
			block->precision = block->precision * 10 + ft_chartoint(format[i]);
	}
	else if (format[i] == '*')
	{
		if (block->precision == -1)
		{
			block->width = va_arg(ap, int);
			if (block->width < 0)
			{
				block->minus = 1;
				block->width = block->width * -1;
			}
		}
		else
			block->precision = va_arg(ap, int);
	}
}

void	append_block_info(va_list ap, char *format, t_info *block, int i)
{
	if (format[i] == '0' && block->width == 0 && block->precision == -1)
		block->zero = 1;
	else if (format[i] == '-')
		block->minus = 1;
	else if (format[i] == '.')
		block->precision = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, block, i);
}

int		ft_printformat(va_list ap, char *format)
{
	int		i;
	int		result;
	t_info	*block;

	i = 0;
	result = 0;
	block = (t_info*)malloc(sizeof(t_info));
	if (!block)
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			block_initialize(block);
			while (format[++i] && !ft_strchr(TYPE, format[i]))
				append_block_info(ap, format, block, i);
			block->type = format[i++];
			result += printBlockType(ap, block);
		}
	}
	free(block);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = ft_printformat(ap, (char*)format);
	va_end(ap);
	return (result);
}
