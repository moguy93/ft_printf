/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:39:32 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 06:49:29 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Affiche le champs en 0 ou espace.
*/

static inline unsigned int	display_field(t_prf *prf, unsigned int j)
{
	int				field;
	char			*str;

	if (prf[j].field < 1)
		return (0);
	field = prf[j].field - 1;
	if (!(str = ft_strnew(field + 2)))
		error("Malloc ", prf);
	while (field >= 0)
	{
		if (prf[j].zero == YES && prf[j].neg == NO)
			str[field] = '0';
		else
			str[field] = ' ';
		field--;
	}
	ft_putstr(str);
	ft_strdel(&str);
	return ((unsigned int)prf[j].field);
}

/*
** Affiche le signe ou le 0x.
*/

static inline unsigned long	display_sign(t_prf *prf, unsigned int j)
{
	unsigned long	count;

	count = 0;
	if (prf[j].nb_neg == YES)
		write(1, "-", 1);
	else if (prf[j].posi == YES)
		write(1, "+", 1);
	else if (prf[j].hex == YES)
		write(1, "0x", 2);
	else if (prf[j].hexm == YES)
		write(1, "0X", 2);
	else if (prf[j].o == YES)
		write(1, "0", 1);
	if (prf[j].space == YES && prf[j].posi == NO)
		write(1, " ", 1);
	if (prf[j].hex == YES || prf[j].hexm == YES)
		count += 2;
	if (prf[j].posi == YES || prf[j].nb_neg == YES || prf[j].o == YES \
			|| prf[j].space == YES)
		count++;
	return (count);
}

/*
** Affiche la precision pour bdiouxX.
*/

static inline unsigned int	display_accuracy(t_prf *prf, unsigned int j, bool o)
{
	int				accuracy;
	char			*str;

	if (((prf[j].convert != STR && prf[j].convert != S && prf[j].convert != C
					&& prf[j].convert != F && prf[j].convert != MODULO) \
				|| o == 1) && prf[j].accuracy > 0)
	{
		accuracy = prf[j].accuracy - 1;
		if (!(str = ft_strnew(accuracy + 2)))
			error("Malloc ", prf);
		while (accuracy >= 0)
		{
			str[accuracy] = '0';
			accuracy--;
		}
		ft_putstr(str);
		ft_strdel(&str);
		return ((unsigned int)prf[j].accuracy);
	}
	else
		return (0);
}

/*
** Affiche le champs, et le signe ou 0x.
*/

static inline unsigned long	display_all(t_prf *prf, unsigned int j)
{
	unsigned long	count;

	count = 0;
	if (prf[j].neg == YES || prf[j].zero == YES)
	{
		count += display_sign(prf, j);
		if (prf[j].neg == NO)
			count += (unsigned long)display_field(prf, j);
		count += (unsigned long)display_accuracy(prf, j, 0);
		if (prf[j].str)
			ft_putstr((const char*)prf[j].str);
	}
	else
	{
		count += (unsigned long)display_field(prf, j);
		count += display_sign(prf, j);
		count += (unsigned long)display_accuracy(prf, j, 0);
		if (prf[j].str)
			ft_putstr((const char*)prf[j].str);
	}
	if (prf[j].convert == F)
		count += (unsigned long)display_accuracy(prf, j, 1);
	if (prf[j].neg == YES)
		count += (unsigned long)display_field(prf, j);
	return (count);
}

/*
** Affiche le resultat.
*/

unsigned int				display(t_prf *prf, unsigned int j)
{
	unsigned long	count;
	const char		c = 0;

	count = 0;
	if (prf[j].convert == C && prf[j].un == 0)
	{
		if (prf[j].neg == NO)
			count += (unsigned long)display_field(prf, j);
		write(1, &c, 1);
		count++;
		if (prf[j].neg == YES)
			count += (unsigned long)display_field(prf, j);
	}
	else
	{
		count += display_all(prf, j);
		if (prf[j].str)
		{
			count += (unsigned long)ft_strlen((const char*)prf[j].str);
			ft_strdel(&(prf[j].str));
		}
	}
	return (count);
}
