/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:21:33 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:35 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_oct_memory(char *memory, int pc, int *arg, int oct)
{
	int	bit;
	int	move;

	move = 0;
	bit = 0;
	while (oct--)
	{
		ft_memcpy(&bit, &memory[(pc++) % MEM_SIZE], 1);
		*arg = (*arg << move) | bit;
		move = 8;
	}
}

void	cpy_oct_memory(char *memory, int pc, int arg, int oct)
{
	char	bit;
	int		move;
	int		mask;

	move = 24;
	arg = swap_int32(arg);
	while (oct--)
	{
		mask = 0xFF << move;
		bit = (arg & mask) >> move;
		ft_memcpy(&memory[(pc++) % MEM_SIZE], &bit, 1);
		move -= 8;
	}
}
