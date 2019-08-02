/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:58:44 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:16:22 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		j;
	char	*new;

	j = 0;
	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (s[j])
		{
			new[j] = f(s[j]);
			j++;
		}
		return (new);
	}
	return (NULL);
}
