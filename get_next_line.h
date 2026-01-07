/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-05 15:27:05 by tphuwian          #+#    #+#             */
/*   Updated: 2026-01-05 15:27:05 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *str);
int		find_ad_nl(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*extract_nl(char *stash);
char	*get_next_line(int fd);
char	*read_stash(int fd, char *stash);
char	*clear_stash(char *stash);
char	*ft_strdup( char *s1);
char	*for_free(char *stash, char *box);

#endif
