/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_opt_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:41 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_champ(t_vminfo *vm)
{
	int		i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->nb_champs)
	{
		ft_printf("* Player %d, weighing %d Bytes, \"%s\" %s.\n",
			vm->champ[i].number,
			vm->champ[i].size,
			vm->champ[i].name,
			vm->champ[i].comment);
	}
}

static void		take_n_bytes(char *mem_pc, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (ft_strlen(ft_putchar_hex(mem_pc[i])) < 2)
			ft_printf("0%s ", ft_putchar_hex(mem_pc[i]));
		else
			ft_printf("%s ", ft_putchar_hex(mem_pc[i]));
	}
}

void			opt_verbose(int op, t_process *prc, t_vminfo *vm, int p_index)
{
	int		i;

	i = -1;
	if (!prc->ok_arg)
		ft_printf("P% 5d | %s", p_index, g_op[op - 1].op);
	prc->ok_arg = 0;
	while (++i < 3)
	{
		if (TYPE(i) == T_REG)
			ft_printf(" r%d", ARG(i));
		else if (TYPE(i) == T_DIR || TYPE(i) == T_IND)
			ft_printf(" %d", ARG(i));
	}
	if (op != 9)
	{
		ft_printf("\nADV %d (0x%04x -> 0x%04x) ", CURSOR, PC - CURSOR, PC);
		take_n_bytes(vm->memory + (PC - CURSOR), CURSOR);
	}
}

void			cycle_opt_check(t_vminfo *vm)
{
	t_list			*proc;

	proc = vm->process.first;
	if (vm->graph)
	{
		ft_printf("\033[200A");
		ft_printf("\n\n\n\n\n\n\n");
		ft_printf("TOTAL LIVE : %d\n", vm->nb_live);
		ft_printf("Max Check : %d\n", vm->check);
		dump_memory(vm, proc, vm->process.len);
		if (vm->dump == vm->cycles)
			exit(-1);
	}
	else if (vm->dump == vm->cycles)
	{
		dump_memory(vm, proc, vm->process.len);
		exit(-1);
	}
}
