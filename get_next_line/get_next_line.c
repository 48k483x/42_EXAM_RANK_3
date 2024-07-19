#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static char *ft_strjoin(char *s, char c)
{
    char *new;
    int i = 0;

    while (s && s[i])
        i++;
    if (!(new = malloc(i + 2)))
        return (NULL);
    i = 0;
    while (s && s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = c;
    new[i + 1] = '\0';
    free(s);
    return (new);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int pos = 0, bytes = 0;
    char *line = NULL;
    char c;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (pos >= bytes)
        {
            pos = 0;
            if ((bytes = read(fd, buf, BUFFER_SIZE)) <= 0)
                break;
        }
        c = buf[pos++];
        if (!(line = ft_strjoin(line, c)))
            return (NULL);
        if (c == '\n')
            break;
    }
    return (line);
}
