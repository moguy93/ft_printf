/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 01:56:35 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 07:14:40 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*nine_to_ten(char *str)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	if (!(ret = ft_strnew(ft_strlen(str) + 2)))
		return (NULL);
	ret[0] = '1';
	while (str[j])
	{
		if (str[j] == '9')
			ret[i] = '0';
		else
			ret[i] = str[j];
		i++;
		j++;
	}
	ft_strdel(&str);
	return (ret);
}

int					ft_strchrf(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (0);
		i++;
	}
	return (1);
}

/*
** Cast des convertions bdiouxX.
*/

static inline void	cast_nb(t_prf *prf, unsigned int j, va_list ap, bool o)
{
	if (o == 1)
	{
		if (prf[j].cast == I)
			prf[j].n = (int)va_arg(ap, intmax_t);
		if (prf[j].cast == HH)
			prf[j].n = (char)va_arg(ap, intmax_t);
		if (prf[j].cast == H)
			prf[j].n = (short)va_arg(ap, intmax_t);
		if (prf[j].cast == L)
			prf[j].n = (long)va_arg(ap, intmax_t);
		if (prf[j].cast == LL)
			prf[j].n = (intmax_t)va_arg(ap, intmax_t);
		return ;
	}
	if (prf[j].cast == I)
		prf[j].un = (unsigned int)va_arg(ap, uintmax_t);
	if (prf[j].cast == HH)
		prf[j].un = (unsigned char)va_arg(ap, uintmax_t);
	if (prf[j].cast == H)
		prf[j].un = (unsigned short)va_arg(ap, uintmax_t);
	if (prf[j].cast == L)
		prf[j].un = (unsigned long)va_arg(ap, uintmax_t);
	if (prf[j].cast == LL)
		prf[j].un = (uintmax_t)va_arg(ap, uintmax_t);
}

/*
** Cast des convertions cspf et appel de la fonction cast_nb pour bdiouxX.
*/

void				cast(t_prf *prf, unsigned int j, va_list ap)
{
	if (prf[j].convert == C)
		prf[j].un = (unsigned char)va_arg(ap, uintmax_t);
	if (prf[j].convert == S && prf[j].accuracy != 0)
		prf[j].str = ft_strdup(va_arg(ap, const char*));
	else if (prf[j].convert == S && prf[j].accuracy == 0)
		va_arg(ap, const char*);
	if (prf[j].convert == P)
		prf[j].un = (uintmax_t)va_arg(ap, uintmax_t);
	if (prf[j].convert == U || prf[j].convert == O || prf[j].convert == B
			|| prf[j].convert == X || prf[j].convert == XX)
		cast_nb(prf, j, ap, 0);
	if (prf[j].convert == D)
		cast_nb(prf, j, ap, 1);
	if (prf[j].convert == F)
	{
		if (prf[j].cast != LF)
			prf[j].f = (double)va_arg(ap, double);
		else
			prf[j].f = (long double)va_arg(ap, long double);
	}
}
