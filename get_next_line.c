/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitra <ydimitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:51 by ydimitra          #+#    #+#             */
/*   Updated: 2025/11/01 16:44:22 by ydimitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join(char  *s1, char *s2)
{
  char *string;
  int len1;
  int len2;
  int i;
  int j;

  len1 = ft_strlen(s1);
  len2 = ft_strlen(s2);
  string = malloc(len1 + len2 + 1);
  if (!string)
    return (NULL);
  while (s1[i++])
    string[i] = s1[i];
  while (s2[j])
    string[i++] = s2[j++];
  res[i] = '\0';
  free(s1);
  return (string);
}

static char */extract_line(char **stash)
{

}

char	*get_next_line(int fd)
{
	char		*buffer[BUFFER_SIZE + 1];
	ssize_t bytes;
	static char	*stash;

	if (fr < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
  while (bytes_read > 0 && !ft_strchr(stash, '\n'))
  {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
      return(free(stash),stash = NULL, NULL);
    buffer[bytes_read] = '\0';
    stash = ft_join(stash, buffer);
    if (!stash)
      return (NULL);
  } 
	return (extract_line(&stash));
}
