/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wich_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_wich_flags(t_lpr *stc)
{
	int		a;

	a = -1;
	if (stc->flag)
	{
		while (stc->flag[++a])
		{
			if (stc->flag[a] == '-')
				stc->min = 1;
			else if (stc->flag[a] == '0' &&
					stc->precision <= ft_figure(stc->of_int))
				stc->zero = 1;
			else if (stc->flag[a] == '#')
				stc->hash = 1;
			else if (stc->flag[a] == ' ')
				stc->space = 1;
			else if (stc->flag[a] == '+')
				stc->plus = 1;
		}
		if (ft_needle('0', stc->flag) &&
				stc->precision > ft_figure(stc->of_int))
			ft_epur(stc, '0');
	}
}
