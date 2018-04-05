/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:31 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	parse_header(t_champ *champ)
{
	int		ret;
	void	*buf;
	int		size;

	if (!(buf = malloc(sizeof(t_header))))
		return (-1);
	ret = read(champ->fd, buf, sizeof(t_header));
	if (ret != (int)sizeof(t_header)
			|| swap_int32(((t_header *)buf)->magic) != 0xea83f3)
		size = -1;
	else
		size = swap_int32(((t_header *)buf)->prog_size);
	if (!(champ->name = ft_strdup(((t_header *)buf)->prog_name))
			|| !(champ->comment = ft_strdup(((t_header *)buf)->comment)))
		size = -1;
	free(buf);
	return (size);
}

static int	get_champ_code(char *code, t_champ *champ)
{
	int		size;
	int		ret;

	size = parse_header(champ);
	if (size < 0 || size > CHAMP_MAX_SIZE)
		return (1);
	champ->size = size;
	ret = read(champ->fd, code, CHAMP_MAX_SIZE);
	if (ret != size)
		return (1);
	return (0);
}

static int	get_champ_number(t_champ champ[])
{
	int		count;

	count = 0;
	while (count < 5 && champ[count].fd != 0)
		count++;
	return (count);
}

int			create_champion(char *memory, t_champ champs[], t_vminfo *vm)
{
	int			nbr_champs;
	int			champ_pos;
	char		code[CHAMP_MAX_SIZE];
	t_process	prc;

	nbr_champs = get_champ_number(champs);
	if (nbr_champs == 0)
		return (1);
	champ_pos = MEM_SIZE / nbr_champs;
	vm->nb_champs = nbr_champs++;
	while (--nbr_champs > 0)
	{
		ft_bzero(code, CHAMP_MAX_SIZE);
		ft_bzero(&prc, sizeof(t_process));
		if (get_champ_code(code, &champs[nbr_champs - 1]))
			return (1);
		prc.nb = (vm->nb_champs - nbr_champs) + 1;
		prc.pc_pos = champ_pos * (nbr_champs - 1);
		prc.reg[0] = (champs[nbr_champs - 1]).number;
		ft_lstpushfront(&(vm->process), ft_lstnew(&prc, sizeof(t_process)));
		ft_memcpy(memory + (champ_pos * (nbr_champs - 1)),
				code, CHAMP_MAX_SIZE);
	}
	g_nb_prc = vm->nb_champs;
	return (0);
}
