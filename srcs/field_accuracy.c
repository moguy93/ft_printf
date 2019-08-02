/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_accuracy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:44:26 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 06:54:32 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		accu_bdiopux(t_prf *prf, unsigned int j)
{
	size_t	len;

	len = 0;
	if (!prf[j].str || prf[j].accuracy < 0)
		return (1);
	if (prf[j].accuracy >= 0)
		prf[j].zero = NO;
	if (prf[j].accuracy == 0 && ft_strcmp((const char*)prf[j].str, "0") == 0 \
			&& !(prf[j].convert == O && prf[j].hash == YES))
	{
		prf[j].str[0] = '\0';
		return (1);
	}
	len = ft_strlen((const char*)prf[j].str);
	prf[j].accuracy -= (int)len;
	return (0);
}

int		accu_s(t_prf *prf, unsigned int j)
{
	size_t	len;

	len = 0;
	if (!prf[j].str || prf[j].accuracy == -1)
	{
		prf[j].accuracy = -1;
		return (1);
	}
	len = ft_strlen((const char*)prf[j].str);
	len = (len < (size_t)prf[j].accuracy) ? len : (size_t)prf[j].accuracy;
	prf[j].str[len] = '\0';
	return (0);
}

int		field_bdiou(t_prf *prf, unsigned int j)
{
	if (prf[j].field < 1 || !prf[j].str)
		return (1);
	prf[j].field -= ft_strlen((const char*)prf[j].str);
	if (prf[j].accuracy > 0)
		prf[j].field -= prf[j].accuracy;
	return (0);
}

int		field_px(t_prf *prf, unsigned int j)
{
	if (prf[j].field < 1 || !prf[j].str)
		return (1);
	prf[j].field -= (ft_strlen((const char*)prf[j].str));
	if (prf[j].accuracy > 0)
		prf[j].field -= prf[j].accuracy;
	return (0);
}

int		field_sf(t_prf *prf, unsigned int j)
{
	if (!prf[j].str || prf[j].field < 1)
		return (1);
	prf[j].field -= ft_strlen((const char*)prf[j].str);
	if (prf[j].convert == F)
		prf[j].field -= prf[j].accuracy;
	return (0);
}
