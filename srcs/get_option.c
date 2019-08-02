/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:38:48 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 07:05:45 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Recupere la valeur de la precision.
*/

static inline unsigned int	get_accuracy(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j)
{
	unsigned int	k;
	int				nb;

	k = 0;
	nb = 0;
	if (format[i + k] == '.')
	{
		while (format[i + k] == '.')
			i++;
		while (ft_isdigit(format[i + k]) == 1)
		{
			nb = nb * 10 + (int)(format[i + k] - '0');
			k++;
		}
		if (k == 0)
			prf[j].accuracy = 0;
		else
			prf[j].accuracy = nb;
	}
	i = i + k;
	return (get_cast(prf, format, i, j));
}

/*
** Recupere la valeur du champs.
*/

static inline unsigned int	get_field(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j)
{
	unsigned int	k;
	int				nb;

	k = 0;
	nb = 0;
	while (ft_isdigit(format[i + k]) == 1)
	{
		nb = nb * 10 + (int)(format[i + k] - '0');
		prf[j].field = nb;
		k++;
	}
	i = i + k;
	return (get_accuracy(prf, format, i, j));
}

/*
** Recupere la convertion, les options, la precision et le champs.
*/

static inline unsigned int	get_data(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j)
{
	while (ft_strchrf(" #+-.0123456789hlL", (int)format[i]) != 1)
	{
		while (ft_strchrf(" #+-0", (int)format[i]) != 1)
		{
			init_option(prf, j, format[i]);
			i++;
		}
		i = get_field(prf, format, i, j);
	}
	return (get_convertion(prf, format, i, j));
}

/*
** Recupere le texte.
*/

static inline unsigned int	get_string(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j)
{
	unsigned int	k;
	unsigned int	l;

	k = i;
	l = 0;
	while (format[i] != '%' && format[i])
		i++;
	if (!(prf[j].str = ft_strnew((size_t)((i - k) + 1))))
		error("Malloc ", prf);
	while (k + l < i)
	{
		prf[j].str[l] = format[k + l];
		l++;
	}
	return (i);
}

/*
** Gere la recuperation des infos necessaires.
*/

void						get_option(t_prf *prf, const char *format)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] != '%')
			i = get_string(prf, format, i, j);
		else
			i = get_data(prf, format, (i + 1), j);
		j++;
	}
}
