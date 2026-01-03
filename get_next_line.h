#ifndef GET_NEXT_LINE_H 
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int ft_findNL(char *str);
int findAD_NL(char *str);
char *ft_strjoin(char *str1, char *str2);
char *extract_NL(char *stash);
char	*get_next_line(int fd);
char *Read_stash(int fd, char *stash);
char *clear_stash(char *stash);
char *ft_strdup(const char *s1);
char *for_free(char *stash);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# endif