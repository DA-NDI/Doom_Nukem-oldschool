/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:39:56 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/15 19:41:06 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

long int			ft_strtol(char *line);
int					ft_count_digits(int value, int base);
int					get_next_line(const int fd, char **line);
char				*ft_rot_n(char *str, int n);
int					ft_pow(int nb, int pow);
int					ft_is_whitespace(char c);
unsigned char		ft_swap_bits(unsigned char octet);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strzero(char *str);
int					count_bits(unsigned long long nbr);
size_t				ft_intlen(long long int nbr);
char				*ft_reverse(char *s);
char				*ft_reverse_bitwise(char *s);
char				*ft_itoa(int n);
char				*ft_itoa_unsigned(unsigned int n);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_10_8(unsigned long long int nbr);
char				*ft_itoa_base_10_16(unsigned long long int nbr);
char				*ft_itoa_base_10_16x(unsigned long long int nbr);
char				*ft_itoa_long(long int n);
char				*ft_itoa_long_long(long long int n);
char				*ft_itoa_long_long_u(unsigned long long int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_del(char *s1, char *s2);
char				*ft_strjoin_del_dest(char *s1, char *s2);
char				*ft_strjoin_del_all(char *s1, char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_zero_fill(unsigned int *aray, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *big, const char *small, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strcpy(char *dest, char *srt);
size_t				ft_strlen(const char *str);
int					ft_strlen_w(wchar_t *str);
char				*ft_strdup(char *str);
char				*ft_strncpy(char *dest, const char *str, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);

#endif
