#include <stdlib.h>

char f(unsigned int i, char c)
{
	char str;
	str = c + i;
	return (str);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char* ft_strmapi(char const* s, char (*f)(unsigned int, char))
{
	size_t len;
	size_t i;
	char* buff;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	buff = (char*)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (0);
	while (i < len)
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}


#include <stdio.h>

int main()
{
	char str1[] = "abc";
	char* str2;
	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2);
}