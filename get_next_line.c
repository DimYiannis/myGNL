/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/01 14:01:30 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			res;
	static char	*stash;
	char		*stash_start;
	static char	*stashwrite;
	char		*line;
	char		*line_start;
	int			i;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
		stash[0] = '\0';
		stashwrite = stash;
	}
    i = 0;
	stash_start = stash;
    line = malloc(i + 1);
	line_start = line;
	// populate stash
	while ((res = read(fd, buffer, 5)) > 0)
	{
		while (i++ < res)
			*stashwrite++ = buffer[i];
	}
	*stashwrite = '\0';
	free(buffer);
	// check for newline and copy to line
	
	while (*stash_start != '\n' && *stash_start)
		*line++ = *stash_start++;
	*line = '\0';
	if (*stash_start == '\n')
		stash_start++;
	stashwrite = stash;
	while (*stashwrite)
		*stashwrite = *stash_start;
	*stashwrite = '\0';
	return (line_start);
}
