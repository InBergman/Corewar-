/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:21:44 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:47 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		aff_winner(t_vminfo *vm)
{
	int	i;
	int	ok;

	i = vm->nb_champs;
	ok = 0;
	while (--i >= 0)
	{
		if (vm->champ[i].number == vm->last_live)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n", i + 1, \
					vm->champ[i].name);
			ok = 1;
		}
		free(vm->champ[i].name);
		free(vm->champ[i].comment);
	}
	if (!ok)
		ft_printf("No one won !\n");
	ft_lstdel(&vm->process, del_process);
	exit(EXIT_SUCCESS);
}
