
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;

    fd = open("text.txt", O_RDWR);
    if (fd == -1)
        return (NULL);
    printf("%s\n", get_next_line(fd));
}
