/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:10:45 by moguy             #+#    #+#             */
/*   Updated: 2019/01/08 18:48:29 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j > 0)
			if (!(tab[k++] = ft_strsub(s, i, j)))
				return (NULL);
		i = i + j;
	}
	tab[k] = 0;
	return (tab);
}
