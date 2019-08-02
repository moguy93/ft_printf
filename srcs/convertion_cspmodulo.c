/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_cspmodulo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:01:14 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 06:48:34 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Gestion du %%.
*/

int					convertion_modulo(t_prf *prf, unsigned int j)
{
	if (!(prf[j].str = ft_strdup("%")))
		error("Malloc ", prf);
	return (0);
}

/*
** Gestion du %c.
** Gestion du champs pour le cas d'un %c == 0.
*/

int					convertion_c(t_prf *prf, unsigned int j)
{
	unsigned int	i;

	i = 0;
	prf[j].field -= 1;
	if (prf[j].un == 0)
		return (1);
	else
	{
		if (!(prf[j].str = ft_strnew(2)))
			error("Malloc ", prf);
		prf[j].str[0] = (char)prf[j].un;
	}
	return (0);
}

/*
** Gestion du %s, notamment du cas ou str est == NULL.
*/

int					convertion_s(t_prf *prf, unsigned int j)
{
	char			*str2;

	if (!prf[j].str && prf[j].accuracy != 0)
	{
		if (!(str2 = ft_strdup("(null)")))
			error("Malloc ", prf);
		prf[j].str = str2;
		return (1);
	}
	return (0);
}

/*
** Gestion du %p, mise en place de 0x et gestion de l'adresse == NULL.
*/

int					convertion_p(t_prf *prf, unsigned int j)
{
	prf[j].hex = YES;
	prf[j].convert = X;
	ft_itoa_basef(prf, j);
	prf[j].convert = P;
	return (0);
}
