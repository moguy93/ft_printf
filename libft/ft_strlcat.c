/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:04:30 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:16:14 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		dlen;

	d = dst;
	s = src;
	i = size;
	while (i-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
