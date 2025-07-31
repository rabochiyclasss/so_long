/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:58:34 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/06 16:15:21 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
// #include <stdio.h>
// int main()
// {
//     // Создаем новый узел со строкой "Hello"
//     t_list *node = ft_lstnew("Hello");
//     if (node)
//     {
//         // Выводим содержимое узла
//         printf("Содержимое узла: %s\n", (char *)node->content);
//     }
//     else
//     {
//         printf("Ошибка: не удалось создать узел\n");
//     }
//     // Освобождаем память узла
//     free(node);
//     return 0;
// }
