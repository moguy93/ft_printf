/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:13:37 by moguy             #+#    #+#             */
/*   Updated: 2019/06/30 04:16:11 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i] || (s1[i] == '\0' && s2[i] == '\0'))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i + 1] != s2[i + 1] || (s1[i + 1] == '\0' && s2[i + 1] == '\0'))
			return ((unsigned char)s1[i + 1] - (unsigned char)s2[i + 1]);
		if (s1[i + 2] != s2[i + 2] || (s1[i + 2] == '\0' && s2[i + 2] == '\0'))
			return ((unsigned char)s1[i + 2] - (unsigned char)s2[i + 2]);
		if (s1[i + 3] != s2[i + 3] || (s1[i + 3] == '\0' && s2[i + 3] == '\0'))
			return ((unsigned char)s1[i + 3] - (unsigned char)s2[i + 3]);
		if (s1[i + 4] != s2[i + 4] || (s1[i + 4] == '\0' && s2[i + 4] == '\0'))
			return ((unsigned char)s1[i + 4] - (unsigned char)s2[i + 4]);
		if (s1[i + 5] != s2[i + 5] || (s1[i + 5] == '\0' && s2[i + 5] == '\0'))
			return ((unsigned char)s1[i + 5] - (unsigned char)s2[i + 5]);
		if (s1[i + 6] != s2[i + 6] || (s1[i + 6] == '\0' && s2[i + 6] == '\0'))
			return ((unsigned char)s1[i + 6] - (unsigned char)s2[i + 6]);
		i += 7;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
