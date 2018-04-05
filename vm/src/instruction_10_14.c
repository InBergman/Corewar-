/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_10_14.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:20:44 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:20:47 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ldi(t_process *prc, t_vminfo *vm)
{
	int		i;

	i = -1;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	while (++i < 2)
	{
		if (TYPE(i) == T_REG)
			ARG(i) = prc->reg[ARG(i)];
		else if (TYPE(i) == T_IND)
			ARG(i) = get_four_oct(vm->memory, PC + (ARG(i) % IDX_MOD));
	}
	prc->reg[ARG(2)] = get_four_oct(vm->memory, \
			PC + (ARG(0) + ARG(1)) % IDX_MOD);
	return ((PC + CURSOR) % MEM_SIZE);
}

int		sti(t_process *prc, t_vminfo *vm)
{
	int		i;
	int		reg;
	int		ret;

	i = 0;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	while (++i < 3)
	{
		if (TYPE(i) == T_REG)
			ARG(i) = prc->reg[ARG(i)];
		else if (TYPE(i) == T_IND)
			ARG(i) = get_four_oct(vm->memory, PC + (ARG(i) % IDX_MOD));
	}
	reg = swap_int32(prc->reg[ARG(0)]);
	ret = PC + ((ARG(1) + ARG(2)) % IDX_MOD);
	if ((ret %= MEM_SIZE) < 0)
		ret += MEM_SIZE;
	if (ret + 3 >= MEM_SIZE)
		cpy_oct_memory(vm->memory, ret, reg, 4);
	else
		ft_memcpy(vm->memory + ret, &reg, 4);
	return ((PC + CURSOR) % MEM_SIZE);
}

int		frk(t_process *prc, t_vminfo *vm)
{
	t_process	new_prc;

	g_nb_prc++;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	ft_bzero(&new_prc, sizeof(t_process));
	new_prc.pc_pos = (PC + (ARG(0) % IDX_MOD)) % MEM_SIZE;
	new_prc.carry = prc->carry;
	new_prc.alive = prc->alive;
	new_prc.nb = g_nb_prc;
	if (new_prc.pc_pos < 0)
		new_prc.pc_pos += MEM_SIZE;
	ft_memcpy(&new_prc.reg, prc->reg, sizeof(int) * 16);
	ft_lstpushfront(&(vm->process), ft_lstnew(&new_prc, sizeof(t_process)));
	return ((PC + CURSOR) % MEM_SIZE);
}

int		lld(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (TYPE(0) == T_IND)
		ARG(0) = get_four_oct(vm->memory, PC + ARG(0));
	if (!(prc->reg[ARG(1)] = ARG(0)))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		lldi(t_process *prc, t_vminfo *vm)
{
	int		i;

	i = -1;
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	while (++i < 2)
	{
		if (TYPE(i) == T_REG)
			ARG(i) = prc->reg[ARG(i)];
		else if (TYPE(i) == T_IND)
			ARG(i) = get_four_oct(vm->memory, PC + ARG(i));
	}
	if (!(prc->reg[ARG(2)] = get_four_oct(vm->memory, PC + ARG(0) + ARG(1))))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}
