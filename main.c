/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:18:41 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/06 11:51:26 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//
// int	main(void)
// {
// 	int		fd;
// 	char	*s;
//
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
//
// 	s = get_next_line(0);
// 	if (s)
// 	{
// 		printf("%s", s);
// 		free(s);
// 	}
//
// 	close(fd);
// 	return (0);
// }
int main(void)
{
    char *line;

    printf("Type something (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL) // 0 = stdin
    {
        printf("You typed: %s", line);
        free(line);
    }

    printf("\nEOF reached.\n");
    return (0);
}
