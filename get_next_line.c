/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/31 22:04:52 by ydimitra         ###   ########.fr       */
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
    char *line;
    int i;
    

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
        
    }
    i = 0;
    //populate stash
    while ((res = read(fd, buffer, 5)) > 0)
    {
        while (i++ < res)
            *stash++ = buffer[i];
    }
    *stash = '\0';
    free(buffer);
    stash = stash - i;
    // check for newline and copy to line
    while (stash != '\n' && stash)
        *line++ = *stash++;
    *line = '\0';
}
