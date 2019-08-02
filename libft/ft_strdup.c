/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:31:50 by moguy             #+#    #+#             */
/*   Updated: 2019/07/19 08:01:33 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!s1)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
