#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

char	*ft_strchr(const char *string, int searched_char);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int charac);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *first, const char *second, size_t length);

#endif
