#include "libft"

static size_t   countWords(const char *s, char c)
{
    size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char *get_nextw(const char **s, char c)
{
    const char  *start;
    size_t      wlen;

    while (**s == c && **s != '\0')
        (*s)++;    
    start = *s;
    while (**s != c && **s != '\0')
        (*s)++;
    wlen = *s - start;
    return (ft_substr(start, 0, wlen));
}

static void freew(char **buff, size_t count)
{
    size_t 

    i = 0;
    while (i < count)
    {
        free(buff[i]);
        i++;
    }
    free(buff);
}

char **ft_split(char const *s, char c)
{
    char    **buff;
    size_t  buff_count;
    size_t  i;

    if (!s)
        return (NULL);
    buff_count = countWords(s, c);
    buff = (char **)malloc((buff_count + 1) * sizeof(char *));
    if (!buff)
        return (NULL);
    i = 0;
    while (i < buff_count)
    {
        buff[i] = get_nextw(&s, c);
        if (!buff[i])
        {
            freew(buff, i);
            return (NULL);
        }
        i++;
    }
    buff[i] = NULL;
    return (buff);
}
