/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-29 18:12:17 by tphuwian          #+#    #+#             */
/*   Updated: 2025-12-29 18:12:17 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char    *GNL(int fd)
{
    static char *Buffer;
    char *result;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    Buffer = Read_stash(fd, Buffer);
    if(Buffer == NULL)
        return(NULL);
    result = extract_NL(Buffer);
    Buffer = clear_stash(Buffer);
    return(result);
}
char *Read_stash(int fd, char *stash)
{
    char *box;
    char *temp;
    int n;

    box = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(box == NULL)
        return(NULL);
    while(ft_findNL(stash) == 0)
    {
        n = read(fd, box, BUFFER_SIZE);
        if(n < 0)
        {
            free(stash);
            free(box);
            return(NULL);
        }
        if(n == 0)
            break;
        box[n] = '\0';
        temp = ft_strjoin(stash, box);
        free(stash);
        stash = temp;
    }
        free(box);
        return(stash);
}
char *clear_stash(char *stash)
{
    int len;
    char *box;
    int i;
    i = 0;

    if(findAD_NL(stash) == -1)
    {
        free(stash);
        return(NULL);
    }
    else
    {
        len = findAD_NL(stash) + 1;
        box = (char *)malloc(sizeof(char) * (ft_strlen(stash) - len + 1));
        if(!box)
        {
            free(stash);
            return(NULL);
        }
        while(stash[len])
            box[i++] = stash[len++];
        box[i] ='\0';
        free(stash);
        return(box);
    }
}
