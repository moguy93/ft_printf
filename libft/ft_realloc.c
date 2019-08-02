/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:36 by moguy             #+#    #+#             */
/*   Updated: 2019/05/10 20:36:03 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, int size)
{
	char	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strcpy(new, ptr);
	ft_strdel(&ptr);
	return (new);
}
