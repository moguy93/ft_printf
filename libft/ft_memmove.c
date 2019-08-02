/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:40:47 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:14:30 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src > dst)
		while (len--)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	else
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}
