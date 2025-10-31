/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/31 22:30:40 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
    int fd;
    char *buffer;
    int res;
    static char *stash;
    static char *stashwrite;
    char *line;
    int i;
    char *stash_start;
    char *line_start;
    
    fd = open("text.txt", O_RDWR);
    if (fd == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    if (!stash)
    {
        stash = malloc()
        if (!stash)
        {
            free(buffer);
            return NULL;
        }
        stash[0] = '\0';
        stashwrite = stash;
    }
    stash_start = stash;
    line_start = line;
    
    i = 0;
    //populate stash
    while ((res = read(fd, buffer, 5)) > 0)
    {
        while (i++ < res)
            *stashwrite++ = buffer[i];
    }
    *stashwrite = '\0';
    free(buffer);

    // check for newline and copy to line
    line = malloc(i + 1);
    while (stash_start != '\n' && stash_start)
        *line++ = *stash_start++;
    *line = '\0';
    
    if (*stash_start == '\n')
        stash_start++;
    stashwrite = stash;
    while(*stashwrite)
        *stashwrite = *stash_start;
    *stashwrite = '\0';
    
    return (line_start);
}
