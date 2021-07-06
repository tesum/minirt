#include "miniRT.h"

// ft_strrchr(c, s[++i]) != 0	-	нашел разделитель
static	int	elements(const char *s, char *c)
{
	size_t	i;
	int		elem;
	int		isseparator;

	isseparator = 1;
	elem = 0;
	i = 0;
	while (s[i])
	{
		if (ft_strrchr(c, s[i]) != 0)
			while (ft_strrchr(c, s[++i]) != 0);
		else if (ft_strrchr(c, s[i]) == 0)
		{
			elem++;
			while (ft_strrchr(c, s[++i]) == 0);
		}
	}
	return (elem);
}

static	int	len_sub(char const *s, char *c, int i)
{
	int	len;

	len = 0;
	while (ft_strchr(c, s[i]) == 0 && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static	void	cs(int elem, char **str)
{
	while (elem >= 0)
	{
		free(str[elem]);
		str[elem] = NULL;
		elem--;
	}
	str = NULL;
}

char	**ft_split_rt(char const *s, char *c)
{
	size_t	i;
	int		elem;
	int		elem_max;
	char	**str;

	if (s == NULL)
		return (NULL);
	elem_max = elements(s, c);
	printf("elem_max = %d\n", elem_max);
	// printf("s = %s|\n", s);
	str = malloc((elem_max + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	elem = 0;
	while (elem < elem_max)
	{
		while (ft_strchr(c, s[i]) != 0)
			i++;
		str[elem] = ft_substr(s, i, len_sub(s, c, i));
		if (!str[elem])
			cs(elem - 1, str);
		elem++;
		i += len_sub(s, c, i);
	}
	str[elem] = NULL;
	return (str);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	*str = NULL;
	str = NULL;
}
