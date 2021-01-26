/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:12:31 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/01 13:47:00 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
size_t				ft_strlcpy(char *dest, char *src, size_t n);
size_t				ft_strlcat(char *dest, char *src, size_t n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				*ft_memset(void *memdest, int symvol, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void *src, size_t n);
void				*ft_memccpy(void *dest, void *src, int ch, size_t n);
void				*ft_memchr(const void *buf1, int ch, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_calloc(size_t num, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *str1, const char *str2,
				size_t length);
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_atoi(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(char *str);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isalnum(int ch);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
int					ft_lstsize(t_list *lst);

#endif
