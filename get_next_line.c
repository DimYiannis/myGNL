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
  
  i = 0;
  j = 0;
   if (!s1)
  {
    s1 = malloc(1);
    if (!s1)
      return (NULL);
    s1[0] = '\0';
  }
  len1 = ft_strlen(s1);
  len2 = ft_strlen(s2);
  string = malloc(len1 + len2 + 1);
  if (!string)
    return (NULL);
  while (s1[i])
  {
    string[i] = s1[i];
    i++;
  }
  while (s2[j])
    string[i++] = s2[j++];
  string[i] = '\0';
  free(s1);
  return (string);
}

static char *extract_line(char **stash)
{
  char *line;
  char *new_stash;
  size_t i;

  i = 0;
  if (!stash)
    return (NULL);
  while ((*stash)[i] && (*stash)[i] != '\n')
    i++;
  if ((*stash)[i] == '\n') 
    line = ft_substr(*stash, 0, i + 1);
  else 
    line = ft_substr(*stash, 0, i);
   if ((*stash)[i] == '\n') 
    new_stash = ft_strdup(*stash + i + 1);
  else 
    new_stash = NULL;
  free(*stash);
  *stash = new_stash;
  return (line);
}

char	*get_next_line(int fd)
{
  char	buffer[BUFFER_SIZE + 1];
	ssize_t bytes;
	static char	*stash;
  	
  if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

  if (!stash)
  {
    stash = malloc(1);
    if (!stash)
        return NULL;
    stash[0] = '\0';
  }
	bytes = 1;
  while (bytes > 0 && !ft_strchr(stash, '\n'))
  {
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes < 0)
      return(free(stash),stash = NULL, NULL);
    buffer[bytes] = '\0';
    stash = ft_join(stash, buffer);
    if (!stash)
      return (NULL);
  } 
	return (extract_line(&stash));
}
