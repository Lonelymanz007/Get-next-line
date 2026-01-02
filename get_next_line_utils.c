/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-18 09:01:40 by tphuwian          #+#    #+#             */
/*   Updated: 2025-12-18 09:01:40 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_findNL(char *str)
{
	int i;
	i = 0;

	while(str[i])
	{
		if(str[i] == '\n')
			return(1);
		i++;
	}
	return(0);
}
int findAD_NL(char *str)
{
	int i;
	i = 0;

	if(!str)
		return(-1);
	while(str[i])
	{
		if(str[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}
char *ft_strjoin(char *str1, char *str2)
{
	int i;
	int j;
	char *box;

	box = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if(box == NULL)
		return(NULL);
	i = 0;
	while(str1[i])
	{
		box[i] = str1[i];
		i++;
	}
	j = 0;
	while(str2[j])
	{
		box[i] = str2[j];
		j++;
		i++;
	}
	box[i] = '\0';
	return(box);
}
char *extract_NL(char *stash)
{
	char *box;
	int len;
	int k;
	k = 0;

	if(findAD_NL(stash) == -1)
		len = ft_strlen(stash) + 1;
	else	
		len = findAD_NL(stash) + 1;
	box = (char *)malloc(sizeof(char) * (len + 1));
	if(!box)
		return(NULL);
	while(k < len)
	{
		box[k] = stash[k];
		k++;
	}
	box[k] = '\0';
	return(box);
}
