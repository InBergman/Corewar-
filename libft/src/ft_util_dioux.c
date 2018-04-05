/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:50 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:50 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_util_dioux_flag(t_lpr *stc)
{
	const char		flag_tab[] = "#+ 0";
	void			(*ft_flags[5])(t_lpr*);
	int				i;
	int				a;

	(ft_flags)[0] = &hash;
	(ft_flags)[1] = &plus;
	(ft_flags)[2] = &space;
	(ft_flags)[3] = &zero;
	(ft_flags)[4] = &minus;
	i = -1;
	a = 0;
	while (flag_tab[++i] && stc->flag)
	{
		a = 0;
		while (stc->flag[a] != flag_tab[i] && stc->flag[a] && flag_tab[i])
			a++;
		if (stc->flag[a] == flag_tab[i])
			ft_flags[i](stc);
	}
}

static void		ft_util_dioux_scnd(t_lpr *stc, int base)
{
	int		len_out;
	char	*tmp;

	len_out = 0;
	ft_wich_flags(stc);
	if (stc->conv != '%')
	{
		tmp = ft_itoa_base(stc->of_int, base);
		len_out = ft_strlen(tmp);
		free(tmp);
	}
	if (stc->precision && len_out < stc->precision)
	{
		stc->field -= (stc->precision);
		if (stc->of_int < 0)
			stc->field--;
	}
	else if (!stc->precision_sign)
		stc->field -= len_out;
	stc->precision -= len_out;
}

void			ft_util_dioux(t_lpr *stc, int base)
{
	ft_util_dioux_scnd(stc, base);
	ft_util_dioux_flag(stc);
	if (!stc->flag[0] && stc->field > 0)
	{
		ft_putichar(stc->field, ' ');
		stc->printed += stc->field;
	}
	while (stc->precision-- > 0)
	{
		if (stc->of_int < 0)
		{
			ft_putchar('-');
			stc->printed++;
			stc->of_int *= -1;
			stc->precision++;
		}
		ft_putchar('0');
		stc->printed++;
	}
}
