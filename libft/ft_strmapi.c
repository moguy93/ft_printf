/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:26:52 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:16:26 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	char			*new;

	j = 0;
	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (s[j])
		{
			new[j] = f(j, s[j]);
			j++;
		}
		return (new);
	}
	return (NULL);
}
