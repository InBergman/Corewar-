/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:22:10 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:22:13 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		dead_process(void *prc, void *dead)
{
	t_process *proc;

	proc = prc;
	if (proc->alive == *((int *)dead))
		return (1);
	else
		proc->alive = 0;
	return (0);
}

void	del_process(void *prc)
{
	free(prc);
}

int		process_live(t_vminfo *vm)
{
	int	match;

	match = 0;
	ft_lstfreematch(&vm->process, &match, dead_process, del_process);
	if (vm->nb_live == 0 || vm->cycle_to_die <= 0)
		aff_winner(vm);
	else if (vm->nb_live < NBR_LIVE)
		vm->check--;
	if (vm->nb_live >= NBR_LIVE || vm->check == 0)
	{
		if ((vm->cycle_to_die -= CYCLE_DELTA) <= 0)
			aff_winner(vm);
		if (vm->verbose)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		vm->check = MAX_CHECKS;
	}
	vm->nb_live = 0;
	return (0);
}
