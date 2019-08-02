/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:58:24 by moguy             #+#    #+#             */
/*   Updated: 2019/06/28 07:45:27 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!(s1 && s2))
		return (NULL);
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	new = ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	return (new);
}
