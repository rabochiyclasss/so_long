/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:30 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:56:30 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
// #include <stdio.h>
// int main()
// {
// 	const char *original = "Hello, World!";
// 	// Дублируем строку
// 	char *copy = ft_strdup(original);
// 	if (copy == NULL)
// 	{
// 		printf("Ошибка: не удалось выделить память\n");
// 		return 1;
// 	}
// 	// Выводим оригинал и копию
// 	printf("Оригинал: %s\n", original);
// 	printf("Копия: %s\n", copy);
// 	// Освобождаем память, выделенную для копии
// 	free(copy);
// 	return 0;
// }
