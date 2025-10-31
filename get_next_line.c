/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/10/31 15:34:02 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int fd;
    char buffer[100];
    int res;
    

    fd = open("text.txt", O_RDWR);
    if (fd == -1)
        return (NULL); 
    res = read(fd, buffer, 5);
    if (res != 5)
        return (NULL);
    
}