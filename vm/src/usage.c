/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:21:54 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:55 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usage(char *str)
{
	int		i;

	i = -1;
	ft_printf("Usage: ./corewar [-d --dump nbr_cycles] [[-n --number]\
champion1.cor] <...>\
\n#######################################################\n");
	while (++i < NB_OPTIONS)
	{
		ft_printf("%s %s, %s\t\t: %s\n", g_options[i].name,
				g_options[i].associated,
				g_options[i].ltl_name,
				g_options[i].doc);
		ft_printf("#######################################################\n");
	}
	ft_error(str);
}
