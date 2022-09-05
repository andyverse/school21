#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	slen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*sjoin(char const *s1, char const *s2)
{
	char		*res_s;
	int		i = 0;
	size_t	j = 0;
	int			len;

	len = slen(s1) + slen(s2) + 1;
	res_s = malloc(len * sizeof(char));
	while (s1[i])
	{
		res_s[i] = s1[i];
		i++;
	}
	while (s2[j])
		res_s[i++] = s2[j++];
	res_s[i] = '\0';
	return (res_s);
}

char* mk_s(char* str, int i, int start)
{
	int j;
	char* res;

	j = 0;
	res = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		res[j] = str[start];
		j++;
		start++;
	}
	res[j] = '\0';
	return (res);
}

char	*readfile(int fd)
{
	int	i = 0;
	char	*tm_s;
	static char *mod_rd = "";
	char	*line = "";
	static int	bytes = 1;

	tm_s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (bytes > 0)
	{
		bytes = read(fd, tm_s, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(mod_rd);
			return (NULL);
		}
		tm_s[bytes] = '\0';
		i = 0;
		while (tm_s[i] != '\0')
		{
			if (tm_s[i++] == '\n')
			{
				line = sjoin(mod_rd, mk_s(tm_s, i, 0));
				free(mod_rd);
				mod_rd = mk_s(tm_s, slen(tm_s), i);
				free(tm_s);
				return (line);
			}
		}
		mod_rd = sjoin(mod_rd, tm_s);
	}
	return (mod_rd);
}

char	*get_next_line(int fd)
{
	static char	*result = "";
	char* str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = readfile(fd);
	if (str != result && result != NULL)
		result = str;
	else
		result = NULL;
	return (result);
}

int	main(int argc, char *argv[])
{
	int			fd;
	int			flag;
	char		*str = "";
	int i = 0;
	// char		*ex;
	// char		*ex1;

	flag = 0;
	(void) argc;
	fd = open (argv[1], O_RDONLY);
	// ex = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// read(fd, ex, BUFFER_SIZE);
	// ex1 = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// read(fd, ex1, BUFFER_SIZE);
	// str = sjoin(ex, ex1, slen(ex1));
	//str = get_next_line(fd);
	//str = get_next_line(fd);
	//str = get_next_line(fd);
	//str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	 while (str != NULL)
	 {
	 	str = get_next_line(fd);
	 	printf("%s", str);
		i++;
	 }
	return (0);
}
