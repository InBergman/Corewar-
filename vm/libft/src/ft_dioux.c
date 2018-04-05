/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_d(t_lpr *stc, char *ptr)
{
	stc->conv = ptr[0];
	ft_util_dioux(stc, 10);
	if (ptr[0] == 'D' && !stc->lmod)
		stc->of_int = (long int)stc->of_int;
	if (stc->lmod)
		ft_lmod_ptr(stc);
	if (!stc->precision_sign || stc->of_int)
		ft_print_base(stc, 10);
	if (stc->min)
		minus(stc);
}

void				ft_o(t_lpr *stc, char *ptr)
{
	stc->conv = ptr[0];
	ft_util_dioux(stc, 8);
	if (ptr[0] == 'O')
		stc->of_int = (unsigned long)stc->of_int;
	if (stc->lmod)
		ft_lmod_ptr(stc);
	if ((!stc->precision_sign || stc->hash) && stc->lmod)
		ft_print_base_max(stc, 8);
	else if (!stc->precision_sign || stc->hash)
		ft_print_base(stc, 8);
	if (stc->min)
		minus(stc);
}

void				ft_u(t_lpr *stc, char *ptr)
{
	stc->conv = ptr[0];
	ft_util_dioux(stc, 10);
	if (stc->lmod)
		ft_lmod_ptr(stc);
	if (ptr[0] == 'U' && !stc->lmod)
		stc->of_int = (unsigned long)stc->of_int;
	if (!stc->precision_sign)
		ft_print_base_max(stc, 10);
	if (stc->min)
		minus(stc);
}

void				ft_x(t_lpr *stc, char *ptr)
{
	int		base;
	char	*tmp;

	base = 16;
	stc->conv = ptr[0];
	ft_util_dioux(stc, base);
	if (stc->lmod)
		ft_lmod_ptr(stc);
	if (ptr[0] == 'X' && !stc->lmod)
		stc->of_int = (unsigned int)stc->of_int;
	if ((!stc->precision_sign || stc->hash) && stc->lmod)
	{
		tmp = ft_itoa_base_ulongmax(stc->of_int, base);
		stc->printed += ft_to_stdout(ptr, tmp);
		free(tmp);
	}
	else if (!stc->precision_sign)
	{
		tmp = ft_itoa_base(stc->of_int, base);
		stc->printed += ft_to_stdout(ptr, tmp);
		free(tmp);
	}
	if (stc->min)
		minus(stc);
}
