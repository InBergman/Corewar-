/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lmod_ptr(t_lpr *stc)
{
	void		(*ft_lmod[6])(t_lpr*);
	const char	*lmod_tab[6] = {"hh", "h", "l", "ll", "j", "z"};
	int			i;

	(ft_lmod)[0] = &ft_hh;
	(ft_lmod)[1] = &ft_h;
	(ft_lmod)[2] = &ft_l;
	(ft_lmod)[3] = &ft_ll;
	(ft_lmod)[4] = &ft_j;
	(ft_lmod)[5] = &ft_z;
	i = 0;
	while (ft_strcmp(lmod_tab[i], stc->lmod) && i < 6)
		i++;
	if (!ft_strcmp(lmod_tab[i], stc->lmod))
		ft_lmod[i](stc);
}

void		ft_hh(t_lpr *stc)
{
	if (stc->conv != 'p')
	{
		stc->of_str = (char *)stc->of_str;
		if (ft_needle(stc->conv, "ouxX"))
			stc->of_int = (unsigned char)stc->of_int;
		else if (ft_needle(stc->conv, "OU"))
			stc->of_int = (unsigned int)stc->of_int;
		else if (ft_needle(stc->conv, "D"))
			stc->of_int = (long int)stc->of_int;
		else
			stc->of_int = (signed char)stc->of_int;
	}
}

void		ft_h(t_lpr *stc)
{
	if (stc->conv != 'p')
	{
		stc->of_str = (char *)stc->of_str;
		if (ft_needle(stc->conv, "D") && stc->of_int > 0)
			stc->of_int = (unsigned short)stc->of_int;
		else if (ft_needle(stc->conv, "dDi"))
			stc->of_int = (short)stc->of_int;
		else if (!ft_needle(stc->conv, "U"))
			stc->of_int = (unsigned short)stc->of_int;
	}
}
