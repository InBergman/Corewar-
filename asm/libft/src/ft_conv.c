/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:54 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:54 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		conv_digit_castinit(char *ptr, t_lpr *stc, va_list ap)
{
	if (!stc->lmod && ptr[0] > 'a' && ptr[0] != 'u')
		stc->of_int = va_arg(ap, int);
	else if (ptr[0] == 'u' && !stc->lmod)
		stc->of_int = va_arg(ap, unsigned int);
	else if (ptr[0] == 'u' && stc->lmod)
		stc->of_int = va_arg(ap, size_t);
	else if (ft_needle(ptr[0], "oOxX") && stc->lmod)
		stc->of_int = va_arg(ap, size_t);
	else if (ptr[0] <= 'X')
		stc->of_int = va_arg(ap, long);
	else
		stc->of_int = va_arg(ap, long long);
}

void			ft_conv_digit(char *ptr, t_lpr *stc, va_list ap)
{
	void		(*ft_dioux[5])(t_lpr*, char*);
	const char	conv[5] = "douxi";
	char		p;
	int			i;

	(ft_dioux)[0] = &ft_d;
	(ft_dioux)[1] = &ft_o;
	(ft_dioux)[2] = &ft_u;
	(ft_dioux)[3] = &ft_x;
	p = ptr[0];
	i = 0;
	if (ptr[0] < 'a' && ptr[0] != 'I')
		p = ptr[0] + 32;
	conv_digit_castinit(ptr, stc, ap);
	while (p != conv[i] && conv[i])
		i++;
	if (p == conv[i])
	{
		if (p == 'i')
			i = 0;
		ft_dioux[i](stc, ptr);
	}
}

void			ft_conv_alpha(char *ptr, t_lpr *stc, va_list ap)
{
	void		(*ft_alpha[5])(t_lpr*);
	const char	conv[2] = "sS";
	int			i;

	(ft_alpha)[0] = &ft_s;
	(ft_alpha)[1] = &ft_bs;
	stc->of_int = -1;
	i = 0;
	stc->conv = ptr[0];
	if (ptr[0] == 's' && !stc->lmod)
		stc->of_str = va_arg(ap, char*);
	else
	{
		stc->conv = 'S';
		stc->of_wstr = va_arg(ap, wchar_t*);
	}
	while (stc->conv != conv[i] && conv[i])
		i++;
	if (!stc->of_str && !stc->of_wstr)
		stc->of_str = "(null)";
	ft_alpha[i](stc);
}

void			ft_conv_alpha_pcc(char *ptr, t_lpr *stc, va_list ap)
{
	void		(*ft_alpha[5])(t_lpr*);
	const char	conv[3] = "pcC";
	int			i;

	(ft_alpha)[0] = &ft_p;
	(ft_alpha)[1] = &ft_c;
	stc->of_int = -1;
	i = 0;
	while (ptr[0] != conv[i] && conv[i])
		i++;
	stc->conv = ptr[0];
	if (ptr[0] == 'C')
		i--;
	stc->of_int = va_arg(ap, unsigned long);
	if (!stc->of_str && !stc->of_wstr)
		stc->of_str = "(null)";
	if (stc->of_int > -1 || stc->field)
		ft_alpha[i](stc);
}

void			ft_no_conv(char *ptr, t_lpr *stc)
{
	void	(*ft_flags[5])(t_lpr*);

	(ft_flags)[0] = &hash;
	(ft_flags)[1] = &plus;
	(ft_flags)[2] = &space;
	(ft_flags)[3] = &zero;
	(ft_flags)[4] = &minus;
	stc->conv = '%';
	if (ptr[0] == '%')
	{
		stc->field--;
		if (stc->field > 0)
			ft_util_dioux(stc, 10);
		ft_putchar('%');
		stc->printed++;
		if (ft_needle('-', stc->flag))
			ft_flags[4](stc);
	}
}
