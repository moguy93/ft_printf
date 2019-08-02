/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:47:02 by moguy             #+#    #+#             */
/*   Updated: 2019/01/18 20:22:52 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrd(double n)
{
	int		nb;

	nb = n;
	n -= nb;
	if (nb < 0)
	{
		n = -n;
		nb = -nb;
		ft_putchar('-');
	}
	ft_putnbr(nb);
	ft_putchar(',');
	while (((n * 1000000) / 1) > 0)
	{
		nb = n * 10;
		n = n * 10;
		if (nb / 1 != 0)
			ft_putnbr(nb);
		else
			ft_putchar('0');
	}
}
