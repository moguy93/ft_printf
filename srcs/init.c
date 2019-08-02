/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:07:45 by moguy             #+#    #+#             */
/*   Updated: 2019/07/18 23:49:44 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Initialisation de la structure.
*/

void			init_prf(t_prf *prf, unsigned int max)
{
	unsigned int	i;

	i = 0;
	while (i < max)
	{
		prf[i].un = 0;
		prf[i].n = 0;
		prf[i].accuracy = -1;
		prf[i].accu = -1;
		prf[i].field = -1;
		prf[i].f = 0;
		prf[i].str = NULL;
		prf[i].max = max;
		prf[i].convert = STR;
		prf[i].cast = I;
		prf[i].space = NO;
		prf[i].hash = NO;
		prf[i].posi = NO;
		prf[i].neg = NO;
		prf[i].zero = NO;
		prf[i].hex = NO;
		prf[i].hexm = NO;
		prf[i].o = NO;
		prf[i++].nb_neg = NO;
	}
}

/*
**  Test et initialisation de la convertion demandee.
*/

char			init_convertion(const char format)
{
	unsigned int		i;
	static const char	tab[12] = {'%', 'c', 's', 'p', 'd', 'i', 'u', 'o', \
		'x', 'X', 'b', 'f'};
	static const char	ret[12] = {MODULO, C, S, P, D, D, U, O, X, XX, B, F};

	i = 0;
	while (tab[i])
	{
		if (tab[i] == format)
			return ((char)ret[i]);
		i++;
	}
	return (STR);
}

/*
** Activation des options demandees.
*/

void			init_option(t_prf *prf, unsigned int j, const char format)
{
	if (format == ' ')
		prf[j].space = YES;
	else if (format == '#')
		prf[j].hash = YES;
	else if (format == '+')
		prf[j].posi = YES;
	else if (format == '-')
		prf[j].neg = YES;
	else if (format == '0')
		prf[j].zero = YES;
}
