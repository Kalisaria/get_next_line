/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeyer <dmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:50:06 by dmeyer            #+#    #+#             */
/*   Updated: 2026/11/06 16:51:18 by dmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}


void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

int	ft_add_node(t_list **resu, char *content)
{
	t_list	*node;
	t_list *lastnd;

	if (!content)
		return (0);
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (0);
	}
	if (*resu == NULL)
		*resu = node;
	else
	{
		lastnd = ft_lstlast(*resu);
		lastnd->next = node;
	}
	return (1);
}

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
