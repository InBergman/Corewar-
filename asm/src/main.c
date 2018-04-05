/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:25:56 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		file_size_calc(t_inst *tmp)
{
	int			size_file;

	size_file = 0;
	while (tmp)
	{
		size_file += count_size_op(tmp);
		tmp = tmp->next;
	}
	return (size_file);
}

int				main(int ac, char **av)
{
	t_header	header;
	t_parser	p;
	t_inst		*tmp;

	ft_bzero(&p, sizeof(t_parser));
	ft_bzero(&header, sizeof(t_header));
	if (ac == 2)
		parser(&header, av[1], &p);
	else
		ft_error("Usage: ./asm <sourcefile.s>\n");
	tmp = p.l_inst;
	header.magic = swap_int32(COREWAR_EXEC_MAGIC);
	header.prog_size = swap_int32(file_size_calc(tmp));
	ft_open(av[1], &header, &p);
	ft_printf("Writing output program to %s\n", p.output);
	ft_del(&p);
	return (0);
}
