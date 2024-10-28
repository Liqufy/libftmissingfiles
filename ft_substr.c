#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	i;
	int	j;
	size_t slen;
	unsigned char *dest;

	dest = (unsigned char *)malloc(len  * sizeof(s) + 1);
	if (!dest)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && i < (start + len))
		dest[j++] = s[i++]; 
	dest[j] = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char a[] = "Hello asd World";

	printf("%s ", ft_substr(a, 6, 3));

	return (0);
}