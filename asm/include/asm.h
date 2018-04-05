/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:03:19 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 18:03:22 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "instruct.h"
# include "op.h"
# include "parser.h"
# include "instruct.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct	s_op
{
	char		*op;
	int			nb_param;
	char		type[3];
	int			opcode;
	int			nb_cycles;
	char		*comment;
	int			smthg;
	int			smthg2;
}				t_op;

extern t_op		g_op[17];

/*
** write_file.c
*/
void			print_data(int fd, t_inst *inst);
int				size_param(int opcode, t_value param);

/*
** manage_file.c
*/
void			ft_open(char *str, t_header *header, t_parser *p);
char			*ft_rename(char *str);
void			edit_file(int fd, void *header);

/*
** ft_del.c
*/
void			ft_del(t_parser *p);

/*
** tools.c
*/
void			ft_trim_leading_space(char **s);
void			ft_trim_ending_space(char **s);
char			*join(char *str, char *buf);
void			remove_comment(char **line);
int				ft_search_each_char(char *str, char *list_of_chars);

/*
** parser_*.c
*/
void			parser(t_header *h, char *file, t_parser *p);
void			parser_header(t_parser *p);
void			parser_inst(t_parser *p);
void			parser_error(t_parser *p, char *msg, char *tok);
void			parser_param(t_parser *p, t_inst *inst, char *s);

/*
** check_label.c
*/
void			check_label(t_parser *p);
int				count_size_op(t_inst *inst);

#endif
