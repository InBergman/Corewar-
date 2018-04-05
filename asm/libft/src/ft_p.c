/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:50 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:50 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_p_of_int_null(t_lpr *stc)
{
	stc->printed += 2;
	stc->field -= 2;
	if (!stc->precision_sign)
		stc->field--;
	ft_util_sspcc(stc);
	ft_putstr("0x");
	if (stc->zero)
	{
		ft_putichar(stc->field, '0');
		stc->printed += stc->field;
	}
	if (stc->precision > 0)
	{
		ft_putichar(--stc->precision, '0');
		stc->printed += stc->precision;
	}
	if (!stc->precision_sign)
	{
		ft_putchar('0');
		stc->printed++;
	}
	if (stc->field > 0 && stc->min)
		minus(stc);
}

static void		ft_p_precision(t_lpr *stc, char *tmp)
{
	if (stc->precision > 0)
	{
		ft_putichar(--stc->precision, '0');
		stc->printed += stc->precision;
	}
	if (!stc->precision_sign)
	{
		stc->printed += ft_strlen(tmp);
		ft_putstr(tmp);
		stc->field -= ft_strlen(tmp);
	}
}

void			ft_p(t_lpr *stc)
{
	char	*tmp;

	if (stc->of_int == 0)
		ft_p_of_int_null(stc);
	else
	{
		tmp = ft_itoa_base(stc->of_int, 16);
		stc->field -= ft_strlen(tmp) + 2;
		ft_util_sspcc(stc);
		hash(stc);
		ft_l(stc);
		stc->precision -= ft_strlen(tmp) - 1;
		ft_p_precision(stc, tmp);
		if (stc->field > 0 && stc->min)
			minus(stc);
		free(tmp);
	}
}
