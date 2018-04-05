/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:51 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:55 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			size_param(int op, t_value param)
{
	int		size;

	size = 0;
	if (param.type == T_REG)
		size++;
	else if (param.type == T_IND)
		size += 2;
	else
	{
		if (op == 1 || op == 2 || op == 6 || (op >= 7 && op <= 8) || op == 13)
			size += 4;
		else
			size += 2;
	}
	return (size);
}

void		print_info(t_value *param, int nbr_param, int fd)
{
	int		i;
	int		a;
	int		x;

	i = -1;
	a = 0;
	x = 64;
	while (++i < nbr_param)
	{
		if (param[i].type == T_REG)
			a |= x;
		else if (param[i].type == T_IND)
			a |= (x * 3);
		else if (param[i].type == T_DIR)
			a |= (x * 2);
		x /= 4;
	}
	write(fd, &a, 1);
}

int			positive_value(t_inst *inst, int i, int size)
{
	int		p;

	p = 0;
	if (size == 4)
		p = swap_int32(inst->param[i].value);
	else if (size == 2)
		p = swap_int16(inst->param[i].value & 0xFFFF);
	else
		p = inst->param[i].value;
	return (p);
}

int			negative_value(t_inst *inst, int i, int size)
{
	int		p;

	p = 0;
	if (size == 4)
		p = swap_int32(inst->param[i].value);
	else if (size == 2)
	{
		p = swap_int32(inst->param[i].value);
		p = p >> 16;
	}
	return (p);
}

void		print_data(int fd, t_inst *inst)
{
	size_t	i;
	int		p;
	int		size;

	i = 0;
	write(fd, &inst->opcode, 1);
	if (inst->opcode != 1 && inst->opcode != 9 && \
			inst->opcode != 12 && inst->opcode != 15)
		print_info(inst->param, inst->nbr_param, fd);
	while (i < inst->nbr_param)
	{
		size = size_param(inst->opcode, inst->param[i]);
		if (inst->param[i].value >= 0)
			p = positive_value(inst, i, size);
		else
			p = negative_value(inst, i, size);
		write(fd, &p, size);
		i++;
	}
}
