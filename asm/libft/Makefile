CPATH = src
HPATH = include
OPATH = obj

CC = /usr/bin/gcc
MKDIR = /bin/mkdir
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror -I $(HPATH) -g

NAME = libft.a
AR = /usr/bin/ar
RANLIB = /usr/bin/ranlib

HEADER = libft.h

SRC			=	ft_atoi.c		\
				ft_atoll.c		\
				ft_error.c		\
				ft_error_int.c	\
				ft_bzero.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_itoa.c		\
				ft_memalloc.c	\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memdel.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar.c	\
				ft_putchar_fd.c	\
				ft_putendl.c	\
				ft_putendl_fd.c	\
				ft_putnbr.c		\
				ft_putnbr_fd.c	\
				ft_putstr.c		\
				ft_putstr_fd.c	\
				ft_strcat.c		\
				ft_strchr.c		\
				ft_strclr.c		\
				ft_strcmp.c		\
				ft_strnum.c		\
				ft_strcmpi.c	\
				ft_strcpy.c		\
				ft_strdel.c		\
				ft_strdup.c		\
				ft_strequ.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strjoin.c	\
				ft_strlcat.c	\
				ft_strlen.c		\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strncat.c	\
				ft_strncmp.c	\
				ft_strncpy.c	\
				ft_strnequ.c	\
				ft_strnew.c		\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_strsplit.c	\
				ft_strstr.c		\
				ft_strsub.c		\
				ft_strtrim.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_lstmap.c		\
				ft_lstnew.c		\
				ft_lstadd.c		\
				ft_lstdel.c		\
				ft_lstdelone.c	\
				ft_lstiter.c	\
				ft_lstpushfront.c\
				ft_lstpushback.c\
				ft_lstpopback.c\
				ft_lstpopfront.c\
				ft_lstcpynode.c\
				print_content.c\
				ft_abs.c		\
				ft_strtoupper.c	\
				ft_strtolower.c	\
				ft_power.c		\
				ft_sqrt.c		\
				sort_in_tab.c	\
				wdmatch.c\
				ft_print_base.c\
				ft_find.c\
				ft_find_flag.c\
				ft_needle.c\
				ft_epur.c\
				ft_to_stdout.c\
				ft_putichar.c\
				ft_check_of.c\
				ft_itoa_base.c\
				ft_itoa_base_ulongmax.c\
				ft_conv.c\
				ft_dioux.c\
				ft_alpha.c\
				ft_p.c\
				ft_atoi_btod.c\
				ft_wstrlen.c\
				ft_flags.c\
				ft_scnd_flags.c\
				ft_lmod.c\
				ft_scnd_lmod.c\
				ft_wich_flags.c\
				ft_util.c\
				ft_util_dioux.c\
				ft_reset_list.c\
				ft_init_list.c\
				ft_widechar.c\
				ft_cast.c\
				get_next_line.c\
				ft_printf.c\
				min_val.c\
				max_val.c\
				swap_int.c\
				ft_figure.c\
				ft_deltab.c\
				ft_strsep.c\
				ft_lstfreematch.c

HFILES = $(patsubst %,$(HPATH)/%, $(HEADER))
CFILES = $(patsubst %,$(CPATH)/%, $(SRC))
OFILES = $(patsubst %.c,$(OPATH)/%.o, $(SRC))

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Building $(NAME)"
	@$(AR) rc $(NAME) $^
	@$(RANLIB) $(NAME)

$(OPATH)/%.o: $(CPATH)/%.c $(HFILES)
	@echo "Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all

$(OPATH):
	@echo "Creation of building directory"
	@$(MKDIR) $(OPATH)

.PHONY: all clean fclean re
