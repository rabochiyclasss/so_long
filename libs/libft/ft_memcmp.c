/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:51:01 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:51:01 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)ptr1;
	p2 = (const unsigned char *)ptr2;
	while (num > 0)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
		num--;
	}
	return (0);
}
// #include <stdio.h>
// int main()
// {
// 	char arr1[] = {1, 2, 3, 4, 5};
// 	char arr2[] = {1, 2, 3, 4, 6};
// 	int result = ft_memcmp(arr1, arr2, 5);
// 	if (result == 0)
// 	{
// 		printf("Массивы равны.\n");
// 	}
// 	else if (result < 0)
// 	{
// 		printf("Первый массив меньше второго.\n");
// 	}
// 	else
// 	{
// 		printf("Первый массив больше второго.\n");
// 	}
// 	return 0;
// }
