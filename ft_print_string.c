/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:51:37 by jealee            #+#    #+#             */
/*   Updated: 2021/02/23 23:06:09 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string_join(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char*)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1len);
	ft_strlcat(result, s2, s2len);
	free(s1);
	free(s2);
	return (result);
}

char	*ft_buf_alloc(char *s, int end, int len)
{
	int		i;
	char	*buf;

	if (end < len)
		end = len;
	buf = (char *)malloc(sizeof(char) * (end + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int		ft_string_width(char **buf, t_info *block)
{
	char	*w;
	int		i;
	int		len;

	if (!buf)
		return (0);
	len = (int)ft_strlen(*buf);
	if (block->w <= len)
		return (len);
	w = (char*)malloc(sizeof(char) * (block->w - len + 1));
	if (!w)
		return (0);
	i = 0;
	while (i < (int)block->w - len)
	{
		if (block->z)
			w[i] = '0';
		else
			w[i] = ' ';
		i++;
	}
	w[i] = '\0';
	if (!block->m)
		*buf = ft_string_join(w, *buf);
	else
		*buf = ft_string_join(*buf, w);
	return (block->w);
}

int		ft_print_string(char *s, t_info *block)
{
	int		result;
	char	*buffer;

	result = 0;
	if (!s)
		s = "(null)";
	if (block->p == -1 || ((size_t)block->p > ft_strlen(s)))
		block->p = ft_strlen(s);
	buffer = ft_buf_alloc(s, block->p, ft_strlen(s));
	result = ft_string_width(&buffer, block);
	ft_putstr(buffer);
	if (buffer)
		free(buffer);
	return (result);
}
