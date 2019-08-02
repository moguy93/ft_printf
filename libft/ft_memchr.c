/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:58:25 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:14:19 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char*)s;
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
			return ((void*)&b[i]);
		i++;
	}
	return (NULL);
}
