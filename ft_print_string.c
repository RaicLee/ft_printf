/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:51:37 by jealee            #+#    #+#             */
/*   Updated: 2021/02/23 14:54:18 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s, t_info *block)
{
	int		result;
	char	*buffer;

	result = 0;
	if (!s)
		s = "(null)";
	if (block->p == -1 || ((size_t)block->p > ft_strlen(s)))
		block->p = ft_strlen(s);
	buffer = 

}
