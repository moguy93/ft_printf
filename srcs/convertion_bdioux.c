/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_bdioux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 04:12:29 by moguy             #+#    #+#             */
/*   Updated: 2019/07/18 23:55:30 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Creation d'un tableau gerant jusqu'a la base 16.
*/

char				*base_tab(t_prf *prf, unsigned int j)
{
	char			*base;

	if (prf[j].convert == P || prf[j].convert == X)
	{
		if (!(base = ft_strdup("0123456789abcdef")))
			error("Malloc ", prf);
	}
	else
	{
		if (!(base = ft_strdup("0123456789ABCDEF")))
			error("Malloc ", prf);
	}
	return (base);
}

/*
** Gestion de %b, %o, %x et %X, itoa_base avec option majuscules.
*/

int					ft_itoa_basef(t_prf *prf, unsigned int j)
{
	char			*base;
	unsigned int	b;
	unsigned int	i;
	uintmax_t		n;

	i = 0;
	n = prf[j].un;
	b = (prf[j].convert == X || prf[j].convert == XX) ? 16 : 8;
	b = (prf[j].convert == B) ? 2 : b;
	base = base_tab(prf, j);
	if (!(prf[j].str = ft_strnew(66)))
		error("Malloc ", prf);
	while (n >= b)
	{
		prf[j].str[i] = base[n % b];
		n = n / b;
		i++;
	}
	prf[j].str[i] = base[n % b];
	ft_strrev(prf[j].str);
	ft_strdel(&base);
	return (0);
}

/*
** Itoa sans protection.
*/

static inline void	itoa_prf(t_prf *prf, unsigned int j)
{
	uintmax_t		n;
	unsigned int	i;

	i = 0;
	n = (prf[j].convert == D) ? (uintmax_t)(prf[j].n) : prf[j].un;
	if (!(prf[j].str = ft_strnew(66)))
		error("Malloc ", prf);
	while (n > 9)
	{
		prf[j].str[i] = (char)(n % 10) + '0';
		n = n / 10;
		i++;
	}
	prf[j].str[i] = (char)n + '0';
	ft_strrev(prf[j].str);
}

/*
** Gestion de %dui et du long long min.
*/

int					ft_itoaf(t_prf *prf, unsigned int j)
{
	if (prf[j].convert == D && prf[j].n < 0)
	{
		prf[j].nb_neg = YES;
		if (prf[j].n == (-9223372036854775807 - 1))
		{
			if (!(prf[j].str = ft_strnew(30)))
				error("Malloc ", prf);
			ft_strcpy(prf[j].str, "9223372036854775808");
			prf[j].n = -prf[j].n;
			return (1);
		}
		prf[j].n = -prf[j].n;
	}
	itoa_prf(prf, j);
	return (0);
}
