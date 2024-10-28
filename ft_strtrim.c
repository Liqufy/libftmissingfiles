#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t 	first;
	size_t 	last;
	char 	*buff;

	if (!s1 && !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	if (first == last || first > last)
		return (ft_strdup(""));
	while (s1[last - 1] && ft_strchr(set, s1[last - 1]))
		last--;
	buff = (char *)malloc(sizeof(char) * (last - first + 1));
	if (buff)
		ft_strlcpy(buff, (s1 + first), last - first + 1);
	return (buff);
}

#include <string.h>
#include <stdio.h>

int main()
{
  char s[] = "**Hello *uckWorld**";

	printf("%s\n", ft_strtrim(s, "*"));
	return (0);
}