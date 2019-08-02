/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:20:13 by moguy             #+#    #+#             */
/*   Updated: 2019/06/22 03:57:02 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (1 / ft_power(nb, ft_abs(power)));
	if (power == 0)
		return (1);
	power--;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
