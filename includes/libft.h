/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 18:59:29 by tpan              #+#    #+#             */
/*   Updated: 2017/03/14 14:06:59 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef char		t_utf8;

int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(const char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
char				*ft_strdup(const char *s1);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strstr(const char *big, const char *little);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
int					ft_wordcount(char *str, char delimiter);
int					ft_wordlength(char *str, char delimiter);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isspace(int c);
void				ft_reverse(char s[]);
void				ft_putendl(char const *s);
int					ft_isnegative(int c);
char				*ft_realloc(char *ptr, size_t size);
size_t				ft_wstrlen(wchar_t const *str);
wchar_t				*ft_wstrndup(const wchar_t *s1, size_t n);
size_t				ft_wcharbits(wchar_t c);
size_t				ft_wstrsize_utf8(const wchar_t *wstr);
wchar_t				ft_utf8charencode(wchar_t c);
int					ft_wctomb(char *s, wchar_t wc);
size_t				ft_wstrnsize_utf8(const wchar_t *wstr, size_t n);
int					ft_ishex(size_t c);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_intmax(intmax_t value, int base);
char				*ft_itoa_base_uintmax(uintmax_t value, int base);
char				*ft_itoa_base_ull(unsigned long long value, int base);
size_t				ft_nbrlen(int nbr);
char				*ft_tolower_str(char *str);
char				*ft_toupper_str(char *str);
size_t				ft_utf8charsize(wchar_t c);
t_utf8				*ft_utf8strencode(const wchar_t *wstr);
t_utf8				*ft_utf8strnencode(const wchar_t *wstr, size_t n);
void				*ft_wchar_memset(void *b, wchar_t c, size_t len);
size_t				ft_wcharsize_utf8(wchar_t c);
wchar_t				*ft_wstrcpy(wchar_t *dst, wchar_t const *src);
wchar_t				*ft_wstrdup(wchar_t *str);

#endif
