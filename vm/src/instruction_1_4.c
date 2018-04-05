/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_1_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:22:26 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:22:30 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		redirect_action(int opcode, t_process *prc, t_vminfo *vm)
{
	int			(*action[16])(t_process*, t_vminfo*);

	action[0] = live;
	action[1] = ld;
	action[2] = st;
	action[3] = ft_add;
	action[4] = ft_sub;
	action[5] = ft_and;
	action[6] = ft_or;
	action[7] = ft_xor;
	action[8] = zjump;
	action[9] = ldi;
	action[10] = sti;
	action[11] = frk;
	action[12] = lld;
	action[13] = lldi;
	action[14] = lfrk;
	action[15] = aff;
	if (opcode)
		return ((action[opcode - 1](prc, vm)) % MEM_SIZE);
	return ((PC + 1) % MEM_SIZE);
}

int		live(t_process *prc, t_vminfo *vm)
{
	int		i;

	i = 4;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	prc->alive++;
	vm->nb_live++;
	while (--i >= 0)
	{
		if (vm->champ[i].number == ARG(0))
		{
			if (vm->verbose)
				ft_printf("Player %d (%s) is said to be alive\n",\
						i + 1, vm->champ[i].name);
			vm->champ[i].nb_live++;
			vm->last_live = ARG(0);
		}
	}
	return ((PC + CURSOR) % MEM_SIZE);
}

int		ld(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (TYPE(0) == T_IND)
		ARG(0) = get_four_oct(vm->memory, PC + (ARG(0) % IDX_MOD));
	if ((!(prc->reg[ARG(1)] = ARG(0))))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		st(t_process *prc, t_vminfo *vm)
{
	int		ret;
	int		reg;

	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (TYPE(1) == T_REG)
		prc->reg[ARG(1)] = prc->reg[ARG(0)];
	else
	{
		reg = swap_int32(prc->reg[ARG(0)]);
		ret = PC + (ARG(1) % IDX_MOD);
		if ((ret %= MEM_SIZE) < 0)
			ret += MEM_SIZE;
		if (ret + 3 >= MEM_SIZE)
			cpy_oct_memory(vm->memory, ret, reg, 4);
		else
			ft_memcpy(vm->memory + ret, &reg, 4);
	}
	return ((PC + CURSOR) % MEM_SIZE);
}

int		ft_add(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (!(prc->reg[ARG(2)] = prc->reg[ARG(0)] + prc->reg[ARG(1)]))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}
