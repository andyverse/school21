#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#ifndef FT_LIB
#define FT_LIB

int				ft_isalpha(int n);

int				ft_isdigit(int n);

int				ft_isalnum(int n);

int				ft_isascii(int n);

int				ft_isprint(int n);

int				ft_strlen(char *str);

void			*ft_memset(void *str, char c, int n);

void			*ft_bzero(void *str, int n);

void			*ft_memcpy(void *dest, const void *sourse, int n);

void			*ft_memmove(void *dest, const void *source, int n);

unsigned int	ft_strlcpy(char *dest, char *source, int n);

unsigned int	ft_strlcat(char *dest, char *source, int n);

int				ft_toupper(int n);

int				ft_tolower(int n);

char			*ft_strchr (const char *str, int c);

char			*ft_strrchr (const char *str, int c);

int				ft_strncmp(char *str1, char *str2, int n);

void			*ft_memchr(const void *arr, int c, size_t n);

int				ft_memcmp(const void *arr1, const void *arr2, size_t n);

char			*ft_strnstr(const char *strB, const char *strA, int n);

int				ft_atoi (const char *s);

void			*ft_calloc(size_t num, size_t size);

char			*ft_strdup(const char *str);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char 			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void 			ft_putnbr_fd(int n, int fd);



#endif