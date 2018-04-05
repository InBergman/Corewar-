/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_s(t_lpr *stc)
{
	int		i;

	i = -1;
	ft_util_sspcc(stc);
	if (!stc->precision_sign)
	{
		while (++i < stc->precision && stc->of_str[i])
		{
			ft_putchar(stc->of_str[i]);
			stc->printed++;
		}
		if (!stc->precision && stc->of_str[0])
		{
			ft_putstr(stc->of_str);
			stc->printed += ft_strlen(stc->of_str);
		}
	}
	if (stc->min)
		minus(stc);
}

static void		ft_bs_call_c(t_lpr *stc, int len_out, int go)
{
	int		i;

	i = -1;
	if (!stc->precision_sign && stc->of_wstr)
		while (stc->of_wstr[++i])
		{
			if (go)
				if (stc->precision - stc->printed <= 0
			|| len_out < (stc->printed + ft_wchar_len(stc->of_wstr[i + 1])))
					break ;
			stc->of_int = stc->of_wstr[i];
			ft_c(stc);
			stc->field = 0;
		}
	else if (!stc->of_wstr)
	{
		ft_putstr(stc->of_str);
		stc->printed += 6;
	}
	else
		ft_util_sspcc(stc);
}

void			ft_bs(t_lpr *stc)
{
	int		i;
	int		go;
	int		len_out;
	int		fld;

	go = 0;
	i = 0;
	len_out = 0;
	if (stc->precision && stc->of_wstr && !stc->precision_sign)
	{
		while (stc->precision >= len_out && stc->of_wstr[i])
			len_out += ft_wchar_len(stc->of_wstr[i++]);
		len_out -= ft_wchar_len(stc->of_wstr[i]);
		stc->field -= len_out;
		go = 1;
	}
	else if (stc->of_wstr && !stc->precision_sign)
		stc->field -= ft_wstrlen(stc->of_wstr);
	fld = stc->field;
	ft_bs_call_c(stc, len_out, go);
	stc->field = fld;
	if (stc->min)
		minus(stc);
}

static void		ft_c_mask(t_lpr *stc)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa_base(stc->of_int, 2);
	len = ft_strlen(tmp);
	if (len <= 7)
		ft_widechar(stc, "0xxxxxxx", tmp, 8);
	else if (len <= 11)
		ft_widechar(stc, "110xxxxx10xxxxxx", tmp, 16);
	else if (len > 11 && len <= 16)
		ft_widechar(stc, "1110xxxx10xxxxxx10xxxxxx", tmp, 24);
	else
		ft_widechar(stc, "11110xxx10xxxxxx10xxxxxx10xxxxxx", tmp, 32);
	free(tmp);
}

void			ft_c(t_lpr *stc)
{
	int		llmod;

	llmod = 0;
	ft_util_sspcc(stc);
	if (stc->lmod)
		if (!ft_strcmp(stc->lmod, "l"))
			llmod = 1;
	if (stc->conv == 'c' && (llmod != 1 || stc->of_int <= 128))
	{
		ft_putchar(stc->of_int);
		stc->printed++;
		if (stc->min)
			minus(stc);
	}
	else
		ft_c_mask(stc);
}
