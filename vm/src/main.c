/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:21:23 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:21:26 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		g_nb_prc = 0;

void			load_champ_fail(t_champ champ[])
{
	int			i;

	i = 4;
	while (--i)
	{
		if (champ[i].size)
		{
			free(champ[i].name);
			free(champ[i].comment);
		}
	}
	ft_putendl("Can't load champ !");
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	char		memory[MEM_SIZE];
	t_champ		champs[4];
	t_vminfo	vminfo;

	ft_bzero(memory, MEM_SIZE);
	ft_bzero(champs, sizeof(t_champ) * 4);
	ft_bzero(&vminfo, sizeof(t_vminfo));
	args(ac, av, champs, &vminfo);
	if (create_champion(memory, champs, &vminfo))
		load_champ_fail(champs);
	vminfo.cycle_to_die = CYCLE_TO_DIE;
	vminfo.check = MAX_CHECKS;
	vminfo.memory = memory;
	vminfo.champ = champs;
	print_champ(&vminfo);
	if (vminfo.dump == 0)
		cycle_opt_check(&vminfo);
	cycle_to_die(&vminfo);
	return (0);
}
