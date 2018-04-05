/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:36:01 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 18:36:03 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <string.h>
# include "struct.h"
# include "op.h"
# include "libft.h"

/*
** champion.c
*/
int		create_champion(char *memory, t_champ champs[4], t_vminfo *vm);

/*
** args.c
*/
int		args(int ac, char **av, t_champ *champs, t_vminfo *vminfo);
int		graph(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i);
int		color(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i);
int		verbose(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i);
int		aff_arg(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i);

/*
** args.c
*/
void	open_file(char **av, t_champ *champs, int *c_index);
int		number(char **av, t_champ *champ, t_vminfo *vminfo, int *c_index);
int		dump(char **av, t_champ *champ, t_vminfo *vminfo, int *c_index);
void	usage(char *str);

/*
** usage.c
*/
void	usage(char *str);

/*
** dump.c
*/
void	dump_memory(t_vminfo *vminfo, t_list *p, size_t len);
char	*ft_putchar_hex(char c);

/*
** cycle.c
*/
void	cycle_to_die(t_vminfo *vm);

/*
** byte info.c
*/
void	byte_info(char info, t_process *prc);
int		get_four_oct(char *memory, int index);
short	get_two_oct(char *memory, int index);
int		count_octets(char *memory, t_process *prc, int i);

/*
** process live.c
*/
int		process_live(t_vminfo *vm);

/*
** op_code.c
*/
int		redirect_action(int opcode, t_process *prc, t_vminfo *vm);
int		live(t_process *prc, t_vminfo *vm);
int		ld(t_process *prc, t_vminfo *vm);
int		st(t_process *prc, t_vminfo *vm);
int		ft_add(t_process *prc, t_vminfo *vm);
int		ft_sub(t_process *prc, t_vminfo *vm);
int		ft_and(t_process *prc, t_vminfo *vm);
int		ft_or(t_process *prc, t_vminfo *vm);
int		ft_xor(t_process *prc, t_vminfo *vm);
int		zjump(t_process *prc, t_vminfo *vm);
int		ldi(t_process *prc, t_vminfo *vm);
int		sti(t_process *prc, t_vminfo *vm);
int		frk(t_process *prc, t_vminfo *vm);
int		lld(t_process *prc, t_vminfo *vm);
int		lldi(t_process *prc, t_vminfo *vm);
int		lfrk(t_process *prc, t_vminfo *vm);
int		aff(t_process *prc, t_vminfo *vm);
void	get_oct_memory(char *memory, int pc, int *arg, int oct);
void	cpy_oct_memory(char *memory, int pc, int arg, int oct);
int		control_opcode(t_process *prc);
int		new_pc(t_process *prc);
void	del_process(void *prc);
void	aff_winner(t_vminfo *vm);

/*
** cycle_opt_check.c
*/
void	cycle_opt_check(t_vminfo *vm);
void	opt_verbose(int op, t_process *prc, t_vminfo *vm, int p_index);
void	print_champ(t_vminfo *vm);

#endif
