/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:52:43 by moguy             #+#    #+#             */
/*   Updated: 2019/01/07 18:41:05 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		if (!(newlst->content = ft_strdup((char*)content)))
			return (NULL);
		newlst->content_size = content_size;
	}
	newlst->next = NULL;
	return (newlst);
}
