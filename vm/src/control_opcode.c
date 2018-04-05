/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_opcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:33 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		control_opcode(t_process *prc)
{
	int i;

	i = 0;
	while (i < g_op[OPC - 1].nb_param)
	{
		if (!(TYPE(i) & g_op[OPC - 1].type[i]))
		{
			prc->ok_arg = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		new_pc(t_process *prc)
{
	int	i;

	i = 0;
	CURSOR = 1;
	if (OPC != 1 && OPC != 9 && OPC != 12 && OPC != 15)
		CURSOR++;
	while (i < g_op[OPC - 1].nb_param)
	{
		if (TYPE(i) == T_REG)
			CURSOR++;
		else if (TYPE(i) == T_DIR)
			CURSOR += 4;
		else if (TYPE(i) == T_IND)
			CURSOR += 2;
		i++;
	}
	return ((PC + CURSOR) % MEM_SIZE);
}
