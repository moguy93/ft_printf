/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 06:49:28 by moguy             #+#    #+#             */
/*   Updated: 2019/07/14 21:48:34 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		option_hash(t_prf *prf, unsigned int j)
{
	if (prf[j].convert == O && prf[j].accuracy < 1 && (prf[j].field == 0 \
				|| prf[j].zero == NO || prf[j].neg == YES) \
			&& prf[j].un != 0)
		prf[j].o = YES;
	else if (prf[j].convert == P || (prf[j].convert == X && prf[j].un != 0))
		prf[j].hex = YES;
	else if (prf[j].convert == XX && prf[j].un != 0)
		prf[j].hexm = YES;
	else
		prf[j].hash = NO;
	return (0);
}

int		option_posi(t_prf *prf, unsigned int j)
{
	if ((prf[j].convert == D || prf[j].convert == F) && prf[j].nb_neg == NO)
		prf[j].posi = YES;
	else
		prf[j].posi = NO;
	return (0);
}

int		option_space(t_prf *prf, unsigned int j)
{
	if ((prf[j].convert == D || prf[j].convert == F) \
			&& prf[j].nb_neg == NO && prf[j].posi == NO \
			&& (prf[j].field < 1 || prf[j].zero == YES || prf[j].neg == YES))
		prf[j].space = YES;
	else
		prf[j].space = NO;
	return (0);
}
