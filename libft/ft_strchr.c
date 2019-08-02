/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:22:55 by moguy             #+#    #+#             */
/*   Updated: 2019/06/28 07:36:17 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cp;

	i = 0;
	if (!(cp = ft_strdup(s)))
		return (NULL);
	while (cp[i])
	{
		if (cp[i] == (char)c)
			return (&cp[i]);
		i++;
	}
	if ((char)c == cp[i])
		return (&cp[i]);
	return (NULL);
}
