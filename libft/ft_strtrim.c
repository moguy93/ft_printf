/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:16:11 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:17:00 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	len = ft_strlen(s) - 1;
	while (ft_is_white_space(s[i]) == 1)
	{
		i++;
		size--;
	}
	if (!s[i])
		return (ft_strdup(""));
	while (ft_is_white_space(s[len]) == 1 && len > 0)
	{
		len--;
		size--;
	}
	if (size == ft_strlen(s))
		return (ft_strdup(s));
	return (ft_strsub(s, i, size));
}
