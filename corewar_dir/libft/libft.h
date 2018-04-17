/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:12:44 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 16:43:19 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_memswap(void **p1, void **p2);
void				ft_simple_del(void *content, size_t len);

size_t				ft_strlen(const char *str);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *arc);
char				*ft_strmove(char *dest, char *arc);
char				*ft_strncpy(char *dest, char *arc, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(char *str, char *to_find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strset(char *str, char c, size_t length_str);
char				*ft_strupper(char *str);
char				*ft_strlower(char *str);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrjoin(char *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strnchr(const char *s, int c, size_t len);
char				*ft_strnnjoin(char const *s1, char const *s2,
		size_t l1, size_t l2);

void				ft_putchar(char c);
void				ft_putlongchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putunbr(unsigned int n);
void				ft_puthex(unsigned int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putlongchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putunbr_fd(unsigned int n, int fd);
void				ft_puthex_fd(unsigned int n, int fd);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstdupone(t_list *elem);
void				ft_lstdelhead(t_list **old_head,
		void (*del)(void *, size_t));

typedef	struct		s_loop
{
	void			*content;
	size_t			content_size;
	struct s_loop	*down;
	struct s_loop	*up;
}					t_loop;

t_loop				*ft_loopnew(void const *content, size_t content_size);
void				ft_loopdel(t_loop **old_head, void (*del)(void *, size_t));
void				ft_loopadd(t_loop **old_head, t_loop *new_head);
void				ft_loopdelhead(t_loop **old_head,
		void (*del)(void *, size_t));

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_is_str_int(char *str);
int					ft_is_str_uint(char *str);

int					ft_atoi(const char *str);
unsigned int		ft_atoui(const char *str);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_uimaxtoa_base(uintmax_t n, int base);
char				*ft_imaxtoa(intmax_t n);

unsigned int		ft_sqrt_uint(unsigned int ui);
int					ft_a_power_b(int a, unsigned int b);

void				ft_progress_bar(int current_state, int max);

#endif
