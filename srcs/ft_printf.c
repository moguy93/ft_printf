/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:48:23 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 07:09:45 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Recupere les valeurs de la va_list et applique les changements necessaires
** aux structures.
*/

static inline void			get_value(t_prf *prf, va_list ap)
{
	unsigned int		i;

	i = 0;
	while (i < prf[0].max)
	{
		if (prf[i].convert != STR)
		{
			cast(prf, i, ap);
			dispatcher(prf, i);
		}
		i++;
	}
}

/*
** Compte le nombre de structure necessaire.
*/

static inline unsigned int	checkf(const char *format)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] != '%' && format[i] && ++count)
			while (format[i] != '%' && format[i])
				i++;
		if (format[i] == '%')
		{
			count++;
			i++;
			while (ft_strchrf(" +-#.lLh0123456789", (int)format[i]) == 0)
				i++;
			if (format[i])
				i++;
		}
	}
	return (count);
}

/*
** Fonction principale.
*/

unsigned int				ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			ap;
	t_prf			*prf;

	count = 0;
	if ((i = checkf(format)) < 1)
		return (0);
	if (!(prf = (t_prf*)(ft_memalloc(sizeof(t_prf) * i))))
		error("Malloc ", NULL);
	init_prf(prf, i);
	get_option(prf, format);
	va_start(ap, format);
	get_value(prf, ap);
	va_end(ap);
	i = 0;
	while (i < prf[0].max)
	{
		count += display(prf, i);
		i++;
	}
	ft_memdel((void **)&prf);
	return (count);
}
