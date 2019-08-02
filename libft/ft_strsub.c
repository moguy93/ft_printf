/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:44:55 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:16:57 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (s[start + i] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
