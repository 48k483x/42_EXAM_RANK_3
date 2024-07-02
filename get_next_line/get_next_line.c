# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (char *)s;
		s++;
	}
	return NULL;
}

int	_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

void	_strcpy(char *cp, const char *s)
{
	while (*s)
		*cp++ = *s++;
	*cp = '\0';
}

char	*_strdup(char const *s)
{
	int	len = _strlen(s);
	char	*dup = malloc(len + 1);

	if (!dup)
		return NULL;
	_strcpy(dup, s);
	return dup;
}

char *_strjoin(char *join1, const char *join2)
{
	int	len1 = _strlen(join1);
	int	len2 = _strlen(join2);
	char	*join = malloc(len1 + len2 + 1);

	if (!join1 || !join2)
		return NULL;
	if (!join)
		return NULL;
	_strcpy(join, join1);
	_strcpy(join + len1, join2);
	return join;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line;
	int		to_copy; int count;

	line = _strdup(buf);
	if (!(new_line = _strchr(line, '\n')) && (count = read(fd, buf, BUFFER_SIZE)))
	{
		buf[count] = '\0';
		line = _strjoin(line, buf);
	}	
	if (_strlen(line) == 0)
		return (free(line), NULL);
	if (new_line != NULL)
	{
		to_copy = new_line - line + 1;
		_strcpy(buf, new_line + 1);
	}
	else
	{
		to_copy = _strlen(line);
		buf[0] = '\0';
	}
	line[to_copy] = '\0';
	return line;
}
/*
int	main(void)
{
	int fd = open("file.txt", O_RDWR);
	char	*line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}*/
