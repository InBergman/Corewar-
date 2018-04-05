/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_split_size(char *ret, int time)
{
	int		i;
	int		nb;
	char	*str;

	str = ft_strnew(sizeof(char) * 8 + 1);
	str[9] = '\0';
	while (time > 0)
	{
		i = -1;
		while (++i < 8)
			str[i] = ret[i];
		str[i] = '\0';
		nb = ft_atoi_btod(str, 7, 0, 0);
		ft_putchar(nb);
		ret += i;
		time--;
	}
	free(str);
}

void		ft_widechar(t_lpr *stc, char *mask, char *widechar, int len_mask)
{
	char	*change;
	int		i;
	int		save_mask;

	save_mask = len_mask / 8;
	i = ft_strlen(widechar) - 1;
	change = ft_strnew(sizeof(char) * len_mask + 1);
	change[len_mask] = '\0';
	while (--len_mask >= 0)
	{
		if (mask[len_mask] == 'x' && i >= 0)
			change[len_mask] = widechar[i--];
		else
			change[len_mask] = mask[len_mask];
	}
	i = -1;
	while (change[++i])
		if (change[i] == 'x')
			change[i] = '0';
	ft_split_size(change, save_mask);
	stc->printed += save_mask;
	stc->field -= save_mask;
	free(change);
}
