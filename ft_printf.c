/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:08:26 by jealee            #+#    #+#             */
/*   Updated: 2021/03/07 13:03:55 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_block(va_list *ap, t_info *block)
{
	int		result;
	char	type;

	result = 0;
	type = block->t;
	if (type == 'c')
		result = ft_print_c(va_arg(*ap, int), block);
	if (type == '%')
		result = ft_print_c('%', block);
	if (type == 's')
		result = ft_print_s(va_arg(*ap, char *), block);
	if (type == 'd' || type == 'i')
		result = ft_print_id(va_arg(*ap, int), block);
	if (type == 'x' || type == 'X' || type == 'u')
		result = ft_print_ux(va_arg(*ap, unsigned int), block);
	if (type == 'p')
		result = ft_print_p(va_arg(*ap, unsigned long long), block);
	return (result);
}

void	ft_wp_apply(va_list *ap, char *format, t_info *block, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (block->p == -1)
			block->w = block->w * 10 + format[i] - '0';
		else
			block->p = block->p * 10 + format[i] - '0';
	}
	else if (format[i] == '*')
	{
		if (block->p == -1)
		{
			block->w = va_arg(*ap, int);
			if (block->w < 0)
			{
				block->m = 1;
				block->w = block->w * -1;
			}
		}
		else
			block->p = va_arg(*ap, int);
	}
}

void	append_block_info(va_list *ap, char *format, t_info *block, int i)
{
	if (format[i] == '0' && block->w == 0 && block->p == -1)
		block->z = 1;
	else if (format[i] == '-')
		block->m = 1;
	else if (format[i] == '.')
		block->p = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		ft_wp_apply(ap, format, block, i);
}

int		ft_printformat(va_list *ap, char *format)
{
	int		i;
	int		result;
	t_info	*block;

	i = 0;
	result = 0;
	if (!(block = (t_info*)malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			result += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			block_initialize(block);
			while (format[++i] && !ft_strchr("csdiupxX%", format[i]))
				append_block_info(ap, format, block, i);
			block->t = format[i++];
			if ((block->m == 1 || block->p > -1) && block->t != '%')
				block->z = 0;
			result += ft_print_block(ap, block);
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
	result = ft_printformat(&ap, (char*)format);
	va_end(ap);
	return (result);
}
