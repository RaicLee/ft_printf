/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:30:13 by jealee            #+#    #+#             */
/*   Updated: 2021/03/07 17:31:24 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join(char *s1, char *s2, int option)
{
	int		s1len;
	int		s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char*)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1len + 1);
	ft_strlcat(result, s2, s1len + s2len + 1);
	if (option == 1 || option == 3)
		free(s1);
	if (option == 2 || option == 3)
		free(s2);
	return (result);
}

char	*ft_buf_alloc(char *s, int end, int len)
{
	char	*buf;

	if (end > len)
		end = len;
	buf = (char *)malloc(sizeof(char) * (end + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s, end + 1);
	return (buf);
}

int		ft_s_width(char **buf, t_info *block)
{
	char	*w;
	int		i;
	int		len;

	len = (int)ft_strlen(*buf);
	if (block->w <= len)
		return (len);
	if (!(w = (char*)malloc(sizeof(char) * (block->w - len + 1))))
		return (-1);
	i = 0;
	while (i < block->w - len)
	{
		if (block->z)
			w[i++] = '0';
		else
			w[i++] = ' ';
	}
	w[i] = '\0';
	if (!block->m)
		*buf = ft_join(w, *buf, 3);
	else
		*buf = ft_join(*buf, w, 3);
	if (*buf == NULL)
		return (-1);
	return (block->w);
}

int		ft_print_s(char *s, t_info *block)
{
	int		result;
	char	*buffer;

	result = 0;
	if (!s)
		s = "(null)";
	if (block->p == -1 || ((size_t)block->p > ft_strlen(s)))
		block->p = ft_strlen(s);
	buffer = ft_buf_alloc(s, block->p, ft_strlen(s));
	if (!buffer)
		return (-1);
	result = ft_s_width(&buffer, block);
	if (result == -1)
	{
		free(buffer);
		return (result);
	}
	ft_putstr(buffer);
	free(buffer);
	return (result);
}
