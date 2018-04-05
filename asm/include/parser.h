/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:03:53 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 18:03:55 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "asm.h"
# include "instruct.h"

typedef struct		s_parser
{
	char			*file;
	char			*output;
	int				fd;
	char			*line;
	t_header		*h;
	t_inst			*l_inst;
	t_label			*l_lab;
	t_label			*l_top;
	unsigned int	nbr_inst;
	char			is_name;
	char			is_comment;
	unsigned int	count_line;
}					t_parser;

#endif
