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

int	main(void)
{
	int	fd;
  char *s;
	fd = open("text.txt", O_RDWR);
	if (fd == -1)
		return (-1);
  s = get_next_line(fd);

	printf("%s", s);
  free(s);
  s = get_next_line(fd);
	printf("%s", s);
  free(s);
  s = get_next_line(fd);
	printf("%s", s);
  free(s);
  s = get_next_line(fd);
	printf("%s", s);
  free(s);
  close(fd);
}
