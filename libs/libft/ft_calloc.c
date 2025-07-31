/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:17:44 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/03 17:17:44 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	if (num != 0 && (size > 65535 / num))
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
// #include <stdio.h>
// int main()
// {
// 	int *arr = (int *)ft_calloc(5, sizeof(int));
// 	if (arr == NULL)
// 	{
// 		printf("Ошибка: не удалось выделить память\n");
// 		return 1;
// 	}
// 	for (int i = 0; i < 5; i++)
// 	{
// 		arr[i] = 2 * i;
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	free(arr);
// 	return 0;
// }
