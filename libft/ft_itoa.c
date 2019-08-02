/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:12:45 by moguy             #+#    #+#             */
/*   Updated: 2019/01/25 06:26:25 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_while(int n, int size, char *str)
{
	size--;
	while (n > 9)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	str[size] = n + '0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		nb;

	nb = n;
	size = 1;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		size++;
	}
	if (n >= 0)
		if (!(str = ft_strnew(size)))
			return (NULL);
	if (n < 0)
	{
		if (!(str = ft_strnew(++size)))
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	str = ft_while(n, size, str);
	return (str);
}
