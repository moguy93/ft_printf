/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:02:03 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:14:22 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((char*)s1)[i] == ((char*)s2)[i] && i < (n - 1))
		i++;
	return ((unsigned char)((char*)s1)[i] - (unsigned char)((char*)s2)[i]);
}
