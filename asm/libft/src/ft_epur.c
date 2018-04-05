/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:48 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:48 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_epur(t_lpr *stc, char toerase)
{
	int		i;
	int		a;
	int		b;
	int		cnt;
	char	*new_sub;

	i = -1;
	cnt = 0;
	a = ft_strlen(stc->flag);
	while (stc->flag[++i])
		if (stc->flag[i] == toerase)
			cnt++;
	new_sub = ft_memalloc((sizeof(char) * (a - cnt) + 1));
	i = -1;
	b = -1;
	while (++i <= a)
		if (stc->flag[i] != toerase)
			new_sub[++b] = stc->flag[i];
	new_sub[a - cnt] = '\0';
	free(stc->flag);
	stc->flag = ft_strdup(new_sub);
}
