/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fonction_lib.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:46:46 by moguy             #+#    #+#             */
/*   Updated: 2019/07/11 23:19:16 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Swap 2 char d'une string.
*/

void				swap_char(char *str, char a, char b)
{
	unsigned int	i;
	unsigned int	j;
	char			tmp;

	i = 0;
	j = 0;
	while (str[i] != a)
		i++;
	while (str[j] != b)
		j++;
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

/*
** Retourne l'index de la position de la premiere occurence de needle
** dans haystack et -1 en cas d'echec.
*/

int					locate_alnum(const char *haystack, const char *needle)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j])
		{
			if (needle[j] == haystack[i])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

/*
** Strdup jusqu'a len caracteres.
*/

char				*ft_strndup(const char *str, int len)
{
	char			*dup;

	if (!str || len < 0)
		return (NULL);
	if (!(dup = ft_strnew((size_t)len)))
		return (NULL);
	while (len-- >= 0)
		dup[len] = str[len];
	return (dup);
}

/*
** Strjoin qui free les chaines de caracteres passees en parametres.
*/

char				*ft_strjoinf(char *s1, char *s2)
{
	char			*new;

	if (!(s1 && s2))
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	new = ft_strcpy(new, s1);
	ft_memdel((void**)&s1);
	new = ft_strcat(new, s2);
	ft_memdel((void**)&s2);
	return (new);
}

/*
** Affiche l'erreur sur la sortie d'erreur et free.
*/

void				error(const char *str, t_prf *prf)
{
	unsigned int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	if (prf)
	{
		while (i < prf[i].max)
		{
			if (prf[i].str != NULL)
				ft_strdel(&(prf[i].str));
			i++;
		}
		ft_memdel((void**)&prf);
	}
	exit(EXIT_FAILURE);
}
