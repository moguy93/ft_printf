/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:16:40 by moguy             #+#    #+#             */
/*   Updated: 2019/07/15 02:11:03 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			tmp;

	i = 0;
	j = 0;
	if (!str)
		return ;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j--;
		i++;
	}
}
