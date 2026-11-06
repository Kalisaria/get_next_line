/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeyer <dmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:49:34 by dmeyer            #+#    #+#             */
/*   Updated: 2026/11/06 12:28:25 by dmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, (del));
		*lst = aux;
	}
}
void ft_split(char *s, t_list res)
{
	int		len;
	int		i;
	char	*aux;

	aux = s;
	i = 0;
	if(aux[i] == '\0' || aux[i] == '0' )
		return ;
	while(aux)
	
}

char	*get_next_line(int fd)
{
	ssize_t			cases;
	char			*s;
	char			*aux;
	static int		conc;
	static t_list	*res;

	if(!fd)
		return (NULL);
	if (!res->next && concat == 1)
	{
		aux = res->content;
		ft_lstdelone(res);
		read(fd, s, BUFFER_SIZE);
		ft_split(s, *res);
	}
	else
	{
		if (!fd)
			return (NULL);
		s = malloc(BUFFER_SIZE * sizeof(char *) + 1);
		if(!s)
			return (NULL);
		cases = read(fd, s, BUFFER_SIZE);
		if (cases == -1)
			return (NULL);
	}
	ft_split(s, *res);
}
