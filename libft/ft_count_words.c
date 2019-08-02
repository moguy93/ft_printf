/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:45:51 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:12:58 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(const char *s, const char c)
{
	int			i;
	size_t		count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i] != c && s[i] != '\0')
				count++;
			while (s[i] != c && s[i])
				i++;
		}
		return (count);
	}
	return (0);
}
