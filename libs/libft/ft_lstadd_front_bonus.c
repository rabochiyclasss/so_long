/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:58:28 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:58:28 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
// #include <stdio.h>
// int main()
// {
//     t_list *head = NULL;
//     t_list *node1 = ft_lstnew("Node 1");
//     t_list *node2 = ft_lstnew("Node 2");
//     ft_lstadd_front(&head, node1); // Добавляем node1 в начало списка
//     ft_lstadd_front(&head, node2); // Добавляем node2 перед node1
//     // Выводим список
//     t_list *current = head;
//     while (current)
//     {
//         printf("Содержимое узла: %s\n", (char *)current->content);
//         current = current->next;
//     }

//     return 0;
// }
