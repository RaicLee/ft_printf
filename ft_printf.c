/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:08:26 by jealee            #+#    #+#             */
/*   Updated: 2021/02/19 00:11:51 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			i++;
		}
	}
	free(block);
	va_arg(ap,int);
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
