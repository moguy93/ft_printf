/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:50:29 by moguy             #+#    #+#             */
/*   Updated: 2019/06/28 07:45:44 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	if (!(ft_strlen(s1) >= ((size_t)i + ft_strlen(s2) + 1)))
	{
		while (s2[j])
		{
			s1[i + j] = s2[j];
			j++;
		}
		s1[i + j] = '\0';
		return (s1);
	}
	return (NULL);
}
