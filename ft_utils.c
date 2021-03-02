/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:18:52 by jealee            #+#    #+#             */
/*   Updated: 2021/03/03 00:11:18 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	block_initialize(t_info *block)
{
	block->m = 0;
	block->z = 0;
	block->w = 0;
	block->p = -1;
	block->t = 0;
	block->b = 10;
	block->s = 1;
}

int		ft_putchar(char ch)
{
	return (write(1, &ch, sizeof(char)));
}

int		ft_putstr(char *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	return (0);
}

int		ft_getnumlen(unsigned long long nbr, t_info *block)
{
	int	i;

	if (!nbr && block->p != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr/=block->b;
		i++;
	}
	return (i);
}

char	*ft_getbase(char t)
{
	if (t == 'u' || t == 'd' || t == 'i')
		return ("0123456789");
	if (t == 'p' || t == 'x')
		return ("0123456789abcdef");
	if (t == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

