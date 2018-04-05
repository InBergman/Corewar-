/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			minus(t_lpr *stc)
{
	if (stc->field > 0)
	{
		ft_putichar(stc->field, ' ');
		stc->printed += stc->field;
	}
}

void			plus(t_lpr *stc)
{
	if (ft_needle(stc->conv, "di"))
	{
		if (stc->of_int >= 0)
			stc->field--;
		if (!stc->min && !stc->zero)
		{
			while (stc->field-- > 0)
			{
				ft_putchar(' ');
				stc->printed++;
			}
		}
		if (stc->of_int < 0)
		{
			ft_putchar('-');
			stc->of_int = ft_abs(stc->of_int);
			stc->printed++;
		}
		else
		{
			ft_putchar('+');
			stc->printed++;
		}
	}
}

void			space(t_lpr *stc)
{
	if (!stc->plus && !stc->min && !ft_needle(stc->conv, "oOuxXcCsSp"))
	{
		if (!ft_needle(stc->conv, "dDioOuUxX"))
			stc->field--;
		if (stc->of_int < 0)
		{
			ft_putchar('-');
			stc->of_int = ft_abs(stc->of_int);
			stc->printed++;
		}
		else if (stc->of_int >= 0)
		{
			ft_putchar(' ');
			stc->field--;
			stc->printed++;
		}
		if (!stc->zero && stc->field > 0)
		{
			ft_putichar(stc->field, ' ');
			stc->printed += stc->field;
		}
	}
}
