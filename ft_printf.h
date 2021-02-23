/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:13:37 by jealee            #+#    #+#             */
/*   Updated: 2021/02/23 23:09:15 by jealee           ###   ########.fr       */
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
	int			m;
	int			z;
	int			w;
	int			p;
	char		t;
	int			b;
	int			s;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_printformat(va_list ap, char *format);
int				ft_print_block(va_list ap, t_info *block);
void			check_width_and_prec(va_list ap, char *format, t_info *block, int i);
void			append_block_info(va_list ap, char *format, t_info *block, int i);

void			block_initialize(t_info	*block);
int				ft_putchar(char ch);
int				ft_putstr(char *s);

int				ft_print_char(int c, t_info *block);
int				ft_char_width(int width, int len, int zero);

int				ft_print_string(char *s, t_info *block);
char			*ft_string_join(char *s1, char *s2);
char			*ft_buf_alloc(char *s, int end, int len);
int				ft_string_width(char **buf, t_info *block);
#endif
