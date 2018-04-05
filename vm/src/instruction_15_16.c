/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_15_16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:20:57 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:00 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		lfrk(t_process *prc, t_vminfo *vm)
{
	t_process	new_prc;

	g_nb_prc++;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	ft_bzero(&new_prc, sizeof(t_process));
	new_prc.pc_pos = (PC + ARG(0)) % MEM_SIZE;
	new_prc.carry = prc->carry;
	new_prc.alive = prc->alive;
	new_prc.nb = g_nb_prc;
	if (new_prc.pc_pos < 0)
		new_prc.pc_pos += MEM_SIZE;
	ft_memcpy(&new_prc.reg, prc->reg, sizeof(int) * 16);
	ft_lstpushfront(&(vm->process), ft_lstnew(&new_prc, sizeof(t_process)));
	return ((PC + CURSOR) % MEM_SIZE);
}

int		aff(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (vm->aff)
	{
		ft_putstr("Aff: ");
		write(1, &prc->reg[ARG(0)], 1);
		ft_putchar('\n');
	}
	return ((PC + CURSOR) % MEM_SIZE);
}
