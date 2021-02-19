/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:13:37 by jealee            #+#    #+#             */
/*   Updated: 2021/02/19 20:47:23 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define TYPE "csdiupxX%"

typedef	struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	char		type;
	int			base_num;
	int			sign_num;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_printformat(va_list ap, char *format);

void			block_initialize(t_info	*block);
int				ft_putchar(char ch);
int				ft_chartoint(char ch);
#endif
