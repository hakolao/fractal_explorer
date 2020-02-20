/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:42:13 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 16:06:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 50
# define MAX_FD 65536

# define TRUE 1
# define FALSE 0

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_pixel_bounds
{
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
}				t_pixel_bounds;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
int				ft_atoi(const char *str);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
char			*ft_itoa_base(int nb, int base);
char			*ft_itoa(int n);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list*));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list*));
t_list			*ft_strsplit_lst(char const *str, char c);
void			*ft_lstfold(t_list *lst, void *(*f)(void*, void*));
void			*ft_realloc(void *ptr, size_t size_in, size_t size_out);
void			ft_lstappend(t_list **alst, t_list *new);
int				get_next_line(const int fd, char **line);
int				ft_isqrt(int num);
void			ft_strfill(char **str, char c, size_t len);
float			ft_sqrt(const float x);
size_t			ft_lstlen(t_list *lst);
int				ft_lmap_int(int nb, int *in_minmax, int *out_minmax);
double			ft_lmap_double(double nb, double *in_minmax,
				double *out_minmax);
double			ft_abs(double nb);
double			ft_max_double(double *arr, size_t size);
int				ft_max_int(int *arr, size_t size);
double			ft_min_double(double *arr, size_t size);
int				ft_min_int(int *arr, size_t size);
void			ft_pixel_foreach(t_pixel_bounds *limits,
				void *params, void (*f)(int pixel_i, int x, int y,
				void *params));
char			*ft_itoa_long(long int nb);
void			ft_sort_int_tab(int *tab, unsigned int size, int dir);
long double		ft_abs_long_double(long double nb);
long double		ft_powl(double nb, int pow);
char			*ft_ftoa(long double nb, int precision);
void			ft_str_rev(char *str);
int				ft_match(char *s1, char *s2);

#endif
