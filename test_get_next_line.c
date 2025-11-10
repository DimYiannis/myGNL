#include "get_next_line.h"

static char	*no_stash(char *s)
{
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	return (s);
}

static char	*ft_join(char *s1, char *s2)
{
	char	*string;
	int		len1;
	int		len2;
	int		i;
	int		j;
	// static int 	read_fail = 0;

	// read_fail++;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	string = malloc(len1 + len2 + 1);
	// if (read_fail > 2)
	// {
	// 	free(string);
	// 	string = NULL;
	// }

	if (!string)
		return (free(s1), NULL); /// EVAL Correction
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

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i;

	i = 0;
	if (!stash)  // check for !*stash?
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
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;
	static char	*stash;
	
//	read_fail++;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = no_stash(stash);
	if (!stash)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), stash = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_join(stash, buffer);
		if (!stash)
			return ( NULL);
	}
	if (stash && *stash)
		return (extract_line(&stash));
	return (free(stash), stash = NULL, NULL);
}
