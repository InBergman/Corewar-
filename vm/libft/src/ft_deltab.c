/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:15:02 by rdurand           #+#    #+#             */
/*   Updated: 2016/10/15 18:30:43 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&(tab[i++]));
	ft_memdel((void **)&tab);
}