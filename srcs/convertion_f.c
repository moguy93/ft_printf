/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:24:04 by moguy             #+#    #+#             */
/*   Updated: 2019/07/21 06:32:13 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static inline char			*fup(char *tmp, int i)
{
	while (i >= 0)
	{
		if (tmp[i] != '9' && tmp[i] != '.')
		{
			while (tmp[i] != '\0')
			{
				if (tmp[i] == '9')
					tmp[i] = '0';
				else if (tmp[i] >= '0' && tmp[i] < '9')
					tmp[i] = tmp[i] + 1;
				i++;
				if (tmp[i] == '\0')
					return (tmp);
			}
		}
		i--;
		if (tmp[i] == '9' && i == 0)
		{
			if ((tmp = nine_to_ten(tmp)) == NULL)
				return (NULL);
			return (tmp);
		}
	}
	return (tmp);
}

static inline unsigned int	check_next_decimal(t_prf *prf, unsigned int j, \
		unsigned int i)
{
	if (prf[j].str[i] < '5')
		return (0);
	else
		return (1);
}

static inline char			*check_accuracy(t_prf *prf, unsigned int j, \
		char *tmp)
{
	unsigned int	i;
	unsigned int	k;
	char			accu_end;

	k = 0;
	accu_end = prf[j].accu - 3;
	i = (unsigned int)ft_strlen((const char*)tmp);
	while (prf[j].accu > 0)
	{
		if (prf[j].str[k] == '\0')
			tmp[i++] = '0';
		else
			tmp[i++] = prf[j].str[k++];
		prf[j].accu -= 1;
		if (prf[j].accu == 0)
			if (check_next_decimal(prf, j, k) == 1)
				if ((tmp = fup(tmp, (int)i)) == NULL)
					error("Malloc ", prf);
		if (prf[j].accu == 0 || prf[j].accu == accu_end)
		{
			ft_strdel(&prf[j].str);
			return (tmp);
		}
	}
	return (NULL);
}

static inline void			decimal_put(t_prf *prf, unsigned int j)
{
	char			*tmp;
	unsigned int	i;
	long double		f;

	if (!(tmp = ft_strnew(150)))
		error("Malloc ", prf);
	tmp = ft_strcpy(tmp, prf[j].str);
	ft_strdel(&prf[j].str);
	f = prf[j].f - prf[j].n;
	i = (unsigned int)ft_strlen((const char*)tmp);
	tmp[i++] = '.';
	if (prf[j].accuracy > 21)
		prf[j].accu = 21;
	else
		prf[j].accu = (char)prf[j].accuracy;
	prf[j].accuracy -= (int)prf[j].accu;
	while (prf[j].accu > 0)
	{
		prf[j].n = (long long)(f * 10000);
		f = f * 1000;
		f = f - (long long)f;
		ft_itoaf(prf, j);
		tmp = check_accuracy(prf, j, tmp);
	}
	prf[j].str = tmp;
}

int							convertion_f(t_prf *prf, unsigned int j)
{
	size_t			i;

	if (prf[j].accuracy <= -1)
		prf[j].accuracy = 6;
	prf[j].convert = D;
	prf[j].n = (long long)(prf[j].f);
	ft_itoaf(prf, j);
	if (prf[j].f < 0)
		prf[j].f = -(prf[j].f);
	if (prf[j].accuracy == 0)
	{
		prf[j].f = (long double)prf[j].f - (long long)prf[j].f;
		prf[j].f *= 10;
		i = ft_strlen((const char*)prf[j].str);
		if (prf[j].hash == YES)
			prf[j].str[i] = '.';
		if ((int)prf[j].f > 4)
			if ((prf[j].str = fup(prf[j].str, i)) == NULL)
				error("Malloc", prf);
	}
	else
		decimal_put(prf, j);
	prf[j].convert = F;
	return (0);
}
