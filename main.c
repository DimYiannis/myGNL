#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	s = get_next_line(fd);
	if (s)
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
// int main(void)
// {
//     char *line;
//
//     printf("Type something (Ctrl+D to end):\n");
//     while ((line = get_next_line(0)) != NULL)
//     {
//         printf("You typed: %s", line);
//         free(line);
//     }
//
//     printf("\nEOF reached.\n");
//     return (0);
// }
