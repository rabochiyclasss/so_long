/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:58:31 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/06 16:09:59 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
// #include <stdio.h>
// int main()
// {
//     t_list *node1 = ft_lstnew("Node 1");
//     t_list *node2 = ft_lstnew("Node 2");
//     t_list *node3 = ft_lstnew("Node 3");
//     ft_lstadd_front(&node1, node2); // node2 -> node1
//     ft_lstadd_front(&node2, node3); // node3 -> node2 -> node1
//     t_list *last = ft_lstlast(node3);
//     if (last)
//         printf("Последний узел: %s\n", (char *)last->content);
//     return 0;
// }
