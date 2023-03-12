#include "push_swap.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(char *)(s + i) != '\0')
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tot_length;
	int		i;
	int		t;
	char	*j;

	i = 0;
	t = 0;
	if (!s1 || !s2)
		return (NULL);
	tot_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = malloc(sizeof(char) * tot_length);
	if (!j)
		return (0);
	while (s1[t])
		j[i++] = s1[t++];
	t = 0;
	while (s2[t])
		j[i++] = s2[t++];
	j[i] = 0;
	return (j);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	if (i == n)
	{
		--i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
