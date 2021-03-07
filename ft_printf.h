/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:13:37 by jealee            #+#    #+#             */
/*   Updated: 2021/03/07 14:07:10 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

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
int				ft_printformat(va_list *ap, char *format);
int				ft_print_block(va_list *ap, t_info *block);
void			ft_wp_apply(va_list *ap, char *f, t_info *b, int i);
void			append_block_info(va_list *ap, char *f, t_info *b, int i);

void			block_initialize(t_info	*block);
int				ft_putchar(char ch);
int				ft_putstr(char *s);
char			*ft_getbase(char type);

int				ft_print_c(int c, t_info *block);
int				ft_c_width(int width, int zero);

int				ft_print_s(char *s, t_info *block);
char			*ft_join(char *s1, char *s2, int option);
char			*ft_buf_alloc(char *s, int end, int len);
int				ft_s_width(char **buf, t_info *block);

int				ft_print_id(int number, t_info *block);
int				ft_add_minus_id(t_info *block, char **buf);
int				ft_get_num_id(unsigned int number, t_info *block, char **buf);
int				ft_getnumlen_id(unsigned int number, t_info *block);
int				ft_add_minus_id2(int len, t_info *block, char **buffer);

int				ft_print_ux(unsigned int number, t_info *block);

int				ft_print_p(unsigned long long number, t_info *block);
int				ft_get_num_p(unsigned long long number,\
		t_info *block, char **buf);
int				ft_getnumlen_p(unsigned long long nbr, t_info *block);
int				ft_add0x(char **buf);

#endif
