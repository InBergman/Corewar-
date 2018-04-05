/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:42 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_pc(t_list *prc, int *lst_pc, size_t len)
{
	t_process	*tmp;
	size_t		i;

	i = 0;
	while (prc && i < len)
	{
		tmp = (t_process *)prc->content;
		lst_pc[i++] = tmp->pc_pos;
		prc = prc->next;
	}
}

void	print_line(t_vminfo *vminfo, int i, size_t len, int *lst_pc)
{
	size_t	y;
	char	ok;

	y = 0;
	ok = 0;
	while (y < len && !ok && (vminfo->graph || vminfo->color))
	{
		if (i == lst_pc[y++])
		{
			if (vminfo->graph || vminfo->color)
				ft_printf(GREEN"%02s "NORMAL,
						ft_putchar_hex(vminfo->memory[i]));
			else
				ft_printf("%02s ", ft_putchar_hex(vminfo->memory[i]));
			ok++;
		}
	}
	if (!ok)
	{
		if (vminfo->memory[i] != 0 && (vminfo->graph || vminfo->color))
			ft_printf(RED"%02s "NORMAL, ft_putchar_hex(vminfo->memory[i]));
		else
			ft_printf("%02s ", ft_putchar_hex(vminfo->memory[i]));
	}
}

void	dump_memory(t_vminfo *vminfo, t_list *proc, size_t len)
{
	int				i;
	int				*lst_pc;
	unsigned int	adr;

	i = 0;
	adr = 0;
	lst_pc = ft_memalloc(sizeof(int) * len);
	if (vminfo->graph || vminfo->color)
		get_pc(proc, lst_pc, len);
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			adr += 64;
			ft_printf("\n%#06x : ", adr);
		}
		print_line(vminfo, i, len, lst_pc);
		i++;
	}
	free(lst_pc);
	ft_putchar('\n');
}
