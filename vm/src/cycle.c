/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:37 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				count_octets(char *memory, t_process *prc, int i)
{
	if (control_opcode(prc))
		return (1);
	while (++i < 3)
	{
		if (TYPE(i) == T_DIR || TYPE(i) == T_IND)
		{
			if (TYPE(i) == T_DIR && (OPC == 1 || OPC == 2 || \
				(OPC >= 6 && OPC <= 8) || OPC == 13))
			{
				ARG(i) = get_four_oct(memory, PC + CURSOR);
				CURSOR += 2;
			}
			else
				ARG(i) = get_two_oct(memory, PC + CURSOR);
			CURSOR += 2;
		}
		else if (TYPE(i) == T_REG)
		{
			if (!IS_REG((ARG(i) = memory[(PC + CURSOR) % MEM_SIZE])))
				return (1);
			ARG(i)--;
			CURSOR++;
		}
	}
	return (0);
}

static int		check_op_param(t_process *prc, t_vminfo *vm)
{
	int		index;

	if (!CURSOR)
		return (1);
	if (OPC != 1 && OPC != 9 && OPC != 12 && OPC != 15)
	{
		index = (PC + CURSOR) % MEM_SIZE;
		byte_info(vm->memory[index], prc);
		CURSOR++;
	}
	else
		TYPE(0) = T_DIR;
	return (0);
}

static int		check_opcode(t_process *prc, t_vminfo *vm)
{
	bzero(&prc->action, sizeof(t_inst));
	OPC = vm->memory[PC];
	if (OPC < 1 || OPC > 16)
		return (1);
	CURSOR = 1;
	prc->cycle_end = g_op[OPC - 1].nb_cycles - 1;
	return (0);
}

static void		check_prc(t_process *prc, t_vminfo *vm)
{
	if (prc->cycle_end > 0)
		prc->cycle_end--;
	if (!prc->cycle_end)
	{
		if (!check_op_param(prc, vm))
		{
			PC = redirect_action(prc->action.op, prc, vm);
			if (vm->verbose && !vm->graph)
				opt_verbose(prc->action.op, prc, vm, prc->nb);
			ft_bzero(&prc->action, sizeof(t_inst));
		}
		else if (check_opcode(prc, vm))
		{
			PC = (PC + 1) % MEM_SIZE;
			ft_bzero(&prc->action, sizeof(t_inst));
		}
	}
}

void			cycle_to_die(t_vminfo *vm)
{
	t_list	*prc;
	int		i;

	i = 1;
	while (vm->cycle_to_die >= 0)
	{
		vm->cycles++;
		if (vm->verbose && !vm->graph)
			ft_printf("It is now cycle %d\n", vm->cycles);
		prc = vm->process.first;
		while (prc)
		{
			check_prc((t_process *)prc->content, vm);
			prc = prc->next;
		}
		cycle_opt_check(vm);
		if (i == vm->cycle_to_die)
		{
			process_live(vm);
			i = 0;
		}
		i++;
	}
}
