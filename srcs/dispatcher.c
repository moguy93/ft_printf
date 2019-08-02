/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:07:20 by moguy             #+#    #+#             */
/*   Updated: 2019/07/22 00:55:59 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				dispatcher_field_accu(t_prf *prf, unsigned int j)
{
	if (prf[j].convert != S && prf[j].convert != C && prf[j].convert != F \
			&& prf[j].convert != MODULO)
		accu_bdiopux(prf, j);
	else if (prf[j].convert == S)
		accu_s(prf, j);
	if (prf[j].convert == B || prf[j].convert == D || prf[j].convert == O \
			|| prf[j].convert == U)
		field_bdiou(prf, j);
	else if (prf[j].convert == P || prf[j].convert == X || prf[j].convert == XX)
		field_px(prf, j);
	else if (prf[j].convert == S || prf[j].convert == F \
			|| prf[j].convert == MODULO)
		field_sf(prf, j);
}

void				dispatcher_option(t_prf *prf, unsigned int j)
{
	if (prf[j].posi == YES)
		option_posi(prf, j);
	if (prf[j].space == YES)
		option_space(prf, j);
	if (prf[j].hash == YES)
		option_hash(prf, j);
}

void				dispatcher_convert(t_prf *prf, unsigned int j)
{
	int				i;
	static int		(*disp_conv[11])(t_prf *prf, unsigned int j) = {
		convertion_modulo,
		convertion_c,
		convertion_s,
		convertion_p,
		ft_itoaf,
		ft_itoaf,
		ft_itoa_basef,
		ft_itoa_basef,
		ft_itoa_basef,
		ft_itoa_basef,
		convertion_f
	};

	i = (int)prf[j].convert;
	disp_conv[i](prf, j);
}

void				dispatcher(t_prf *prf, unsigned int j)
{
	dispatcher_convert(prf, j);
	dispatcher_field_accu(prf, j);
	dispatcher_option(prf, j);
	if (prf[j].o == YES || prf[j].posi == YES || prf[j].nb_neg == YES \
			|| prf[j].space == YES)
		prf[j].field -= 1;
	if (prf[j].hex == YES || prf[j].hexm == YES)
		prf[j].field -= 2;
}
