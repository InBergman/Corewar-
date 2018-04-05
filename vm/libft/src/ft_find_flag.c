/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int				ft_find_flag(t_lpr *stc, char *ptr)
{
	int		i;

	i = 0;
	while (ft_is_flag(ptr[i]))
		i++;
	if (i > 0)
	{
		stc->flag = ft_strnew(sizeof(char) * i + 1);
		i = -1;
		while (ft_is_flag(ptr[++i]))
			stc->flag[i] = ptr[i];
		stc->flag[i] = '\0';
	}
	else
	{
		stc->flag = ft_strnew(sizeof(char) * 1);
		stc->flag[0] = '\0';
	}
	return (i);
}
