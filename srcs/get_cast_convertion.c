/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cast_convertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 06:08:41 by moguy             #+#    #+#             */
/*   Updated: 2019/07/16 06:41:12 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Recupere la convertion demandee ou definit que c'est du texte.
*/

unsigned int	get_convertion(t_prf *prf, const char *format, unsigned int i, \
		unsigned int j)
{
	if (ft_strchrf("bcdfiopsuxX%", (int)format[i]) != 1)
	{
		prf[j].convert = init_convertion(format[i]);
		return (i + 1);
	}
	else if (format[i] == '\0')
	{
		prf[j].convert = STR;
		prf[j].space = NO;
		return (i);
	}
	else
	{
		if (!(prf[j].str = ft_strndup(&format[i], 1)))
			return (i);
		prf[j].space = NO;
		prf[j].accuracy = -1;
		prf[j].field = -1;
		return (i + 1);
	}
}

/*
** Recupere le cast necessaire.
*/

unsigned int	get_cast(t_prf *prf, const char *format, unsigned int i, \
		unsigned int j)
{
	if (format[i] == 'h')
	{
		if (prf[j].cast != L && prf[j].cast != LL)
			prf[j].cast = H;
		if (format[i + 1] == 'h' && prf[j].cast != L && prf[j].cast != LL)
			prf[j].cast = HH;
		while (format[i] == 'h')
			i++;
	}
	if (format[i] == 'l')
	{
		if (prf[j].cast != L && prf[j].cast != LL)
			prf[j].cast = L;
		if (format[i + 1] == 'l')
			prf[j].cast = LL;
		while (format[i] == 'l')
			i++;
	}
	if (format[i] == 'L')
	{
		prf[j].cast = LF;
		while (format[i] == 'L')
			i++;
	}
	return (i);
}
