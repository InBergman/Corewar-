NAME    = asm

CC      = /usr/bin/gcc
MAKE	= /usr/bin/make
MKDIR   = /bin/mkdir
RM      = /bin/rm

PATH_LIBFT  = libft
PATH_INCL   = include
PATH_SRCS   = src
PATH_OBJ    = obj

CFLAGS  = -Wall -Wextra -Werror -g3 -I $(PATH_LIBFT)/$(PATH_INCL) -I $(PATH_INCL) -g
LDFLAGS = -L libft -lft

LIBFT	= $(PATH_LIBFT)/libft.a

SRCS	 =	main.c\
			op.c\
			tools.c\
			ft_search_each_char.c\
			parser.c\
			parser_header.c\
			parser_inst.c\
			parser_param.c\
			parser_error.c\
			check_labels.c\
			write_file.c\
			manage_file.c\
			ft_del.c

OBJ     = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))

all: $(LIBFT) $(PATH_OBJ) $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(PATH_OBJ)/%.o: $(PATH_SRCS)/%.c $(PATH_INCL)/asm.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(PATH_OBJ):
	$(MKDIR) $@

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

clean:
	$(RM) -rf $(PATH_OBJ)

fclean: clean
	make fclean -C libft
	$(RM) -f $(NAME)

re: fclean all

dump_var:
	echo $(OBJ)

.PHONY: all clean fclean re libft dump_var
