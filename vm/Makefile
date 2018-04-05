# binaries
CC		= /usr/bin/clang
RM		= /bin/rm
MKDIR	= /bin/mkdir

# app name
NAME	= corewar

# dir
ROOT	= $(shell pwd)
OBJDIR	= $(ROOT)/obj
SRCDIR	= $(ROOT)/src
INCDIR	= $(ROOT)/include
LIBDIR	= $(ROOT)/libft
LFTINC	= $(LIBDIR)/include

# compil flags
CFLAGS	= -I $(INCDIR) -I $(LFTINC) -Wall -Wextra -Werror -g
LDFLAGS	= -L $(LIBDIR)
LDLIBS	= -lft -lncurses

# source files
SRC		=	arg_opt.c	\
			arg_opt2.c	\
			main.c	\
			args.c	\
			champion.c \
			dump.c \
			ft_putchar_hex.c \
			cycle.c \
			byte_info.c \
			op.c \
			process_live.c \
			instruction_1_4.c \
			instruction_5_9.c \
			instruction_10_14.c \
			instruction_15_16.c \
			memory_join.c \
			control_opcode.c \
			cycle_opt_check.c\
			winner.c \
			usage.c	

# obj
OBJS	= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	@$(MKDIR) $@

clean:
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

