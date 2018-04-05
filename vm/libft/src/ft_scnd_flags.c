/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scnd_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		hash_xxp(t_lpr *stc)
{
	if (ft_needle(stc->conv, "xp"))
	{
		ft_putchar('x');
		stc->field--;
		stc->printed++;
	}
	else if (stc->conv == 'X')
	{
		ft_putchar('X');
		stc->field--;
		stc->printed++;
	}
}

void			hash(t_lpr *stc)
{
	if ((ft_needle(stc->conv, "oOxXp")) && stc->of_int)
	{
		stc->field--;
		if (stc->field > 0 && !stc->min && !stc->zero && stc->conv != 'p')
		{
			if (stc->conv != 'o')
				stc->field--;
			ft_putichar(stc->field, ' ');
			stc->printed += stc->field;
		}
		ft_putchar('0');
		stc->printed++;
		if (stc->conv == 'o')
			stc->precision--;
		if (ft_needle(stc->conv, "xXp"))
			hash_xxp(stc);
	}
}

void			zero(t_lpr *stc)
{
	if (!stc->min && stc->zero && stc->conv != 'p')
	{
		if (stc->of_int < 0 && ft_needle(stc->conv, "dDioOuUxX"))
		{
			ft_putchar('-');
			stc->of_int *= -1;
			stc->printed++;
		}
		while (stc->field-- > 0)
		{
			ft_putchar('0');
			stc->printed++;
		}
	}
}
