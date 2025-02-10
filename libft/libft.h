/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:15:58 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/07 16:15:58 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "stdarg.h"
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

int			ft_printf(const char *str, ...);
const char	*select_param(const char *str, va_list args, int *len);
void		print_hex(unsigned int n, int *len, int upcase);
void		print_string(va_list args, int *len, int isint);
void		print_unsigned(unsigned int n, int *len);
void		print_address(unsigned long n, int *len, int flag);
int			ft_strlen(char *str);
char		*ft_strncpy(char *dest, char *src, int n);
void		ft_putchar(char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int i);
int			ft_toupper(int i);
char		*ft_strncat(char *dest, char *src, int n);
char		*ft_strcat(char *dest, char *src);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_strstr(char *haystack, char *needle);
char		*ft_strnstr(char *haystack, char *needle, size_t size);
void		*ft_memset(void *s, int c, int n);
void		ft_bzero(void *s, int n);
void		*ft_memcpy(void *dest, const void *src, int n);
void		*ft_memmove(void *dest, const void *src, int n);
char		*ft_strdup(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, int n);
int			ft_strlcat(char *dest, const char *src, size_t size);
int			ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strrchr(const char *str, int c);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strchr(const char *str, int c);
int			ft_memcmp(const void *s1, const void *s2, int n);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
char		*read_file(int fd, char *stash, int *eof);
char		*get_next_line(int fd);
void		add_to_stash(char **stash, char *newline_position);
char		*buffer_to_line(char	*buffer);
void		ft_freed(char *s1, char *s2);
char		*find_newline(char **str, int eof);

#endif