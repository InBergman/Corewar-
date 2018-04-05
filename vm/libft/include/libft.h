/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:23:07 by msireau           #+#    #+#             */
/*   Updated: 2016/11/03 16:26:32 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 4096

# define NORMAL "\e[0m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define WHITE "\e[0;37m"
# define BLUE "\e[0;34m"
# define BROWN "\e[0;33m"
# define CYAN "\e[0;36m"
# define GRAY "\e[1;30m"
# define PURPLE "\e[0;35m"
# define LIGHT_BLUE "\e[1;34m"
# define LIGHT_CYAN "\e[1;36m"
# define LIGHT_GRAY "\e[0;37m"
# define LIGHT_GREEN "\e[1;32m"
# define LIGHT_PURPLE "\e[1;35m"
# define LIGHT_RED "\e[1;31m"

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

typedef struct			s_list_head
{
	size_t				len;
	t_list				*first;
	t_list				*last;
}						t_list_head;

typedef struct			s_lpr
{
	char				*flag;
	char				*lmod;
	char				*of_str;
	wchar_t				*of_wstr;
	char				conv;
	char				*out;
	long long			of_int;
	int					field;
	int					precision;
	int					precision_sign;
	int					min;
	int					zero;
	int					space;
	int					plus;
	int					hash;
	int					printed;
}						t_lpr;

typedef struct			s_gnl_list
{
	int					filedes;
	int					index;
	char				buffer[BUFF_SIZE + 1];
	char				*eol;
	char				*swap;
	char				*new_str;
	struct s_gnl_list	*next;
}						t_gnl_list;

typedef struct			s_buf
{
	int					fd;
	char				*save;
	struct s_buf		*next;
}						t_buf;

/*
** Get next line
*/
int						get_next_line(int const fd, char **line);

/*
** Conversion
*/
int						ft_atoi(const char *str);
long long				ft_atoll(const char *str);
void					ft_bzero(void *s, size_t n);
char					*ft_itoa(int nb);

/*
** Memory management
*/
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src,
		int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_deltab(char **tab);
int						swap_int64(int val1);
int						swap_int32(int val);
int						swap_int16(int val);
int						swap_int8(int val);

/*
** std output
*/
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int nb);
void					ft_putnbr_fd(int nb, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					wdmatch(char *s1, char *s2);
void					ft_error(char *str);
int						ft_error_int(char *str);

/*
** string management
*/
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strcmpi(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlen(const char *str);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s1,
		char (*f)(unsigned int, char));
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strsub(char const *s,
		unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
char					*ft_strtoupper(char *str);
char					*ft_strtolower(char *str);
int						ft_strnum(char *str);
char					*ft_strsep(char **stringp, const char *delim);

/*
** char management
*/
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);

/*
** list management
*/
void					ft_lstdel(t_list_head *head, void (*del)(void*));
void					ft_lstadd(t_list **alst, t_list *ls_new);
t_list					*ft_lstnew(void *content, size_t content_size);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst,
		t_list *(*f)(t_list *elem));
void					ft_lstdelone(t_list_head *head,
		int (*search)(void *, void *), void *match, void (*del)(void *));
int						ft_lstpushfront(t_list_head *head, t_list *link);
int						ft_lstpushback(t_list_head *head, t_list *link);
t_list					*ft_lstcpynode(void *to_lstcontent);
void					print_content(t_list_head *head, void (*ptr)(void *));
void					*ft_lstpopback(t_list_head *head);
void					*ft_lstpopfront(t_list_head *head);

/*
** Maths
*/
int						ft_abs(int nb);
int						ft_power(int nb, int power);
int						ft_sqrt(int nb);
void					sort_in_tab(int *tab, unsigned int size);
int						min_val(int *array, int size);
int						max_val(int *array, int size);

/*
** ft_printf
*/
char					*ft_itoa_base(long long value, int base);
char					*ft_itoa_base_ulongmax(size_t value, int base);
t_lpr					*ft_reset_lpr(t_lpr *stc);
void					ft_widechar(t_lpr *stc, char *mask,
		char *widechar, int len);
int						ft_needle(char c, char *str);
int						ft_figure(int number);
void					ft_putichar(int i, char c);
int						ft_to_stdout(char *ptr, char *to_stdout);
int						ft_check_of(t_lpr *stc);
void					ft_epur(t_lpr *stc, char toerase);
void					ft_free_list(t_lpr *stc);
void					ft_init_struct(t_lpr *stc);
void					ft_print_base(t_lpr *stc, int base);
void					ft_print_base_max(t_lpr *stc, int base);
int						ft_printf(const char *format, ...);
int						ft_find_flag(t_lpr *stc, char *ptr);
int						ft_find_field(t_lpr *stc, char *ptr, int p);
int						ft_find_precision(t_lpr *stc, char *ptr, int p);
int						ft_find_lengthmod(t_lpr *stc, char *ptr, int p);
void					ft_conv_digit(char *ptr, t_lpr *stc, va_list ap);
void					ft_conv_alpha(char *ptr, t_lpr *stc, va_list ap);
void					ft_conv_alpha_pcc(char *ptr, t_lpr *stc, va_list ap);
void					ft_no_conv(char *ptr, t_lpr *stc);
void					ft_split_size(char *ret, int time);
void					ft_d(t_lpr *stc, char *ptr);
void					ft_i(t_lpr *stc, char *ptr);
void					ft_o(t_lpr *stc, char *ptr);
void					ft_u(t_lpr *stc, char *ptr);
void					ft_x(t_lpr *stc, char *ptr);
void					ft_hh(t_lpr *stc);
void					ft_h(t_lpr *stc);
void					ft_l(t_lpr *stc);
void					ft_ll(t_lpr *stc);
void					ft_j(t_lpr *stc);
void					ft_z(t_lpr *stc);
void					ft_lmod_ptr(t_lpr *stc);
int						ft_atoi_btod(char *str, int nb, int i, int result);
int						ft_wstrlen(wchar_t *wstr);
int						ft_wchar_len(wchar_t wchar);
void					ft_wich_flags(t_lpr *stc);
void					ft_util_dioux(t_lpr *stc, int base);
void					ft_util_sspcc(t_lpr *stc);
void					hash(t_lpr *stc);
void					zero(t_lpr *stc);
void					minus(t_lpr *stc);
void					plus(t_lpr *stc);
void					space(t_lpr *stc);
void					ft_s(t_lpr *stc);
void					ft_bs(t_lpr *stc);
void					ft_p(t_lpr *stc);
void					ft_c(t_lpr *stc);
void					ft_lstfreematch(t_list_head *head, void *match, \
		int (*cmp)(void*, void*), void (*del)(void*));
#endif
