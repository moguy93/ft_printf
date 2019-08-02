/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:49:08 by moguy             #+#    #+#             */
/*   Updated: 2019/07/16 05:53:23 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef enum e_convertion	t_convertion;

enum	e_convertion
{
	MODULO, C, S, P, D, U, O, X, XX, B, F, STR
};

typedef enum e_casts		t_casts;

enum	e_casts
{
	I, HH, H, L, LL, LF
};

typedef enum e_status	t_status;

enum	e_status
{
	YES, NO
};

typedef struct		s_prf
{
	uintmax_t		un;
	long double		f;
	intmax_t		n;
	int				accuracy;
	int				field;
	char			*str;
	unsigned int	max;
	char			convert;
	char			cast;
	char			accu;
	bool			space;
	bool			hash;
	bool			posi;
	bool			neg;
	bool			zero;
	bool			hex;
	bool			hexm;
	bool			o;
	bool			nb_neg;
}					t_prf;

unsigned int		ft_printf(const char *format, ...);

int					ft_itoa_basef(t_prf *prf, unsigned int j);

int					ft_itoaf(t_prf *prf, unsigned int j);

int					ft_strchrf(const char *str, int c);

char				*ft_strndup(const char *str, int len);

char				*ft_strjoinf(char *s1, char *s2);

int					locate_alnum(const char *haystack, const char *needle);

void				swap_char(char *str, char a, char b);

char				*nine_to_ten(char *str);

void				nb_up(t_prf *prf, unsigned int j);

char				*base_tab(t_prf *prf, unsigned int j);

void				cast(t_prf *prf, unsigned int j, va_list ap);

void				check_decimal(t_prf *prf, unsigned int j);

int					accu_bdiopux(t_prf *prf, unsigned int j);

int					accu_s(t_prf *prf, unsigned int j);

int					field_bdiou(t_prf *prf, unsigned int j);

int					field_px(t_prf *prf, unsigned int j);

int					field_sf(t_prf *prf, unsigned int j);

int					convertion_c(t_prf *prf, unsigned int j);

int					convertion_f(t_prf *prf, unsigned int j);

int					convertion_p(t_prf *prf, unsigned int j);

int					convertion_s(t_prf *prf, unsigned int j);

int					convertion_modulo(t_prf *prf, unsigned int j);

unsigned int		display(t_prf *prf, unsigned int j);

void				dispatcher_option(t_prf *prf, unsigned int j);

void				dispatcher_field_accu(t_prf *prf, unsigned int j);

void				dispatcher_convert(t_prf *prf, unsigned int j);

void				dispatcher_convert(t_prf *prf, unsigned int j);

void				dispatcher(t_prf *prf, unsigned int j);

void				error(const char *str, t_prf *prf);

unsigned int		get_cast(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j);

unsigned int		get_convertion(t_prf *prf, const char *format, \
		unsigned int i, unsigned int j);

void				get_option(t_prf *prf, const char *format);

void				init_prf(t_prf *prf, unsigned int max);

void				init_option(t_prf *prf, int unsigned i, const char format);

char				init_convertion(const char format);

int					option_space(t_prf *prf, unsigned int j);

int					option_hash(t_prf *prf, unsigned int j);

int					option_posi(t_prf *prf, unsigned int j);

#endif
