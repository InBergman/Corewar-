/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_util_sspcc_scnd(t_lpr *stc)
{
	int			a;
	int			i;
	const char	flag_tab[] = "#+ 0";
	void		(*ft_flags[5])(t_lpr*);

	(ft_flags)[0] = &hash;
	(ft_flags)[1] = &plus;
	(ft_flags)[2] = &space;
	(ft_flags)[3] = &zero;
	(ft_flags)[4] = &minus;
	i = -1;
	if (stc->of_int != -1 && !ft_needle(stc->conv, "pS"))
		stc->field--;
	while (flag_tab[++i] && stc->flag != NULL)
	{
		a = 0;
		while (stc->flag[a] != flag_tab[i] && stc->flag[a] && flag_tab[i])
			a++;
		if (stc->flag[a] == flag_tab[i])
		{
			ft_flags[i](stc);
			break ;
		}
	}
}

void			ft_util_sspcc(t_lpr *stc)
{
	if (stc->of_int == -1 && !stc->precision && !stc->precision_sign)
		stc->field -= ft_strlen(stc->of_str);
	else if (stc->of_int == -1 && stc->precision && stc->of_str[0])
		(int)ft_strlen(stc->of_str) < stc->precision ?
			(stc->field -= (int)ft_strlen(stc->of_str))
			: (stc->field -= stc->precision);
	ft_wich_flags(stc);
	ft_util_sspcc_scnd(stc);
	if (!stc->flag[0])
	{
		ft_putichar(stc->field, ' ');
		if (stc->field > 0)
			stc->printed += stc->field;
	}
}
