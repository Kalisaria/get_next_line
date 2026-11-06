#include "get_next_line.h"

static int	charlen_malloc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
static char	*ft_worddup(char const *s, int len, int concat)
{
	char	*word;
	int		j;

	word = malloc((len + 2) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
	{
		word[j] = '\n';
		word[j + 1] = '\0';
	}
	else
	{
		word[j] = '\0';
		concat = 1;
	}
	return (word);
}
t_list	*ft_split(char *s, t_list *resu, int conc)
{
	char c;

	c = '\n';
	if (!s)
		return (resu);
	while (*s)
	{
		if (*s != c)
		{
			if (!ft_add_node(resu, ft_worddup(s, charlen_malloc(s, c), conc)))
			{
				ft_lstclear(resu, ft_lstdelone);
				return (resu);
			}
			s += charlen_malloc(s, c);
		}
		else
		{
			ft_lstadd_back(resu, ft_lstnew(ft_worddup(s, 0, conc)));
		}
			s++;
	}
	return (resu);
}
