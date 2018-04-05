/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:28 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <limits.h>

short	get_two_oct(char *memory, int index)
{
	short	ret;

	ret = 0;
	index = index % MEM_SIZE;
	if (index < 0)
		index += MEM_SIZE;
	if (index + 1 >= MEM_SIZE)
		get_oct_memory(memory, index, (int *)&ret, 2);
	else
	{
		ft_memcpy(&ret, &memory[index], 2);
		ret = swap_int16(ret & 0xFFFF);
	}
	return (ret);
}

int		get_four_oct(char *memory, int index)
{
	int		ret;

	ret = 0;
	index = index % MEM_SIZE;
	if (index < 0)
		index += MEM_SIZE;
	if (index + 3 >= MEM_SIZE)
		get_oct_memory(memory, index, &ret, 4);
	else
	{
		ft_memcpy(&ret, &memory[index], 4);
		ret = swap_int32(ret);
	}
	return (ret);
}

void	byte_info(char info, t_process *prc)
{
	int				move;
	int				i;
	unsigned char	oct;

	oct = 0xC0;
	move = 6;
	i = -1;
	while (++i < 3)
	{
		if (((info & oct) >> move) == 1)
			TYPE(i) = T_REG;
		else if (((info & oct) >> move) == 2)
			TYPE(i) = T_DIR;
		else if (((info & oct) >> move) == 3)
			TYPE(i) = T_IND;
		else
			TYPE(i) = 0;
		move -= 2;
		oct /= 0x04;
	}
}
