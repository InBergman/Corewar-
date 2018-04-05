/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scnd_lmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_l(t_lpr *stc)
{
	if (stc->conv != 'p')
	{
		if (ft_needle(stc->conv, "oOuUxX"))
			stc->of_int = (unsigned long)stc->of_int;
		if (stc->conv == 'c')
			stc->of_int = (wchar_t)stc->of_int;
	}
}

void				ft_ll(t_lpr *stc)
{
	if (ft_needle(stc->conv, "uU"))
		stc->of_int = (unsigned long long)stc->of_int;
}

void				ft_j(t_lpr *stc)
{
	if (stc->conv != 'p')
	{
		if (ft_needle(stc->conv, "oOuUxX"))
			stc->of_int = (size_t)stc->of_int;
		else
			stc->of_int = (size_t)stc->of_int;
	}
}

void				ft_z(t_lpr *stc)
{
	if (stc->conv != 'p')
	{
		if (ft_needle(stc->conv, "oOuUxX"))
			stc->of_int = (size_t)stc->of_int;
		else
			stc->of_int = (size_t)stc->of_int;
	}
}
