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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	result = extract_nl(stash);
	stash = clear_stash(stash);
	return (result);
}

char	*read_stash(int fd, char *stash)
{
	char	*box;
	char	*temp;
	int		n;

	if (!stash)
		stash = ft_strdup("");
	box = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!box)
		return (for_free(stash, NULL));
	while (find_ad_nl(stash) == -1)
	{
		n = read(fd, box, BUFFER_SIZE);
		if (n < 0)
			return (for_free(stash, box));
		if (n == 0)
			break ;
		box[n] = '\0';
		temp = ft_strjoin(stash, box);
		free(stash);
		stash = temp;
	}
	free(box);
	return (stash);
}

char	*clear_stash(char *stash)
{
	int		len;
	char	*box;
	int		i;

	i = 0;
	if (find_ad_nl(stash) == -1)
		return (for_free(stash, NULL));
	else
	{
		len = find_ad_nl(stash) + 1;
		box = (char *)malloc(sizeof(char) * (ft_strlen(stash) - len + 1));
		if (!box)
			return (for_free(stash, NULL));
		while (stash[len])
		{
			box[i] = stash[len];
			i++;
			len++;
		}
		box[i] = '\0';
		free(stash);
		return (box);
	}
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
