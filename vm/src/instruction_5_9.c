/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_5_9.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:21:09 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:13 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_sub(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (!(prc->reg[ARG(2)] = prc->reg[ARG(0)] - prc->reg[ARG(1)]))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		ft_and(t_process *prc, t_vminfo *vm)
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
	if (!(prc->reg[ARG(2)] = ARG(0) & ARG(1)))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		ft_or(t_process *prc, t_vminfo *vm)
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
	if (!(prc->reg[ARG(2)] = ARG(0) | ARG(1)))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		ft_xor(t_process *prc, t_vminfo *vm)
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
	if (!(prc->reg[ARG(2)] = ARG(0) ^ ARG(1)))
		prc->carry = 1;
	else
		prc->carry = 0;
	return ((PC + CURSOR) % MEM_SIZE);
}

int		zjump(t_process *prc, t_vminfo *vm)
{
	if (count_octets(vm->memory, prc, -1))
		return (new_pc(prc));
	if (prc->carry)
	{
		PC = (PC + (ARG(0) % IDX_MOD)) % MEM_SIZE;
		if (PC < 0)
			PC += MEM_SIZE;
	}
	else
		PC = (PC + CURSOR) % MEM_SIZE;
	return (PC);
}
