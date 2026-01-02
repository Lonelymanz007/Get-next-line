#ifndef get_next_line
# define get_next_line

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int ft_findNL(char *str);
int findAD_NL(char *str);
char *ft_strjoin(char *str1, char *str2);
char *extract_NL(char *stash);
char    *GNL(int fd);
char *Read_stash(int fd, char *stash);
char *clear_stash(char *stash);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#endif